#include "Item.h"

Item::Item()
{
	this->setRadius(20.f);
	this->setOrigin(this->getRadius(), this->getRadius());
	this->setPosition(500, 100);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineColor(sf::Color::Red);
	this->setOutlineThickness(1.f);
	
}

Item::~Item()
{
	if (m_AniIdle != nullptr)
	{
		delete m_AniIdle;
	}
	m_AniIdle = nullptr;

	if (m_AniCollected != nullptr)
	{
		delete m_AniCollected;
	}
	m_AniCollected = nullptr;

	if (m_Body != nullptr)
	{
		//World::GetInstance()->GetWorld()->DestroyBody(m_Body);
	}
}

void Item::Init()
{
	this->setActive(false);
	m_isUsed = false;
	m_isBorn = false;
	CreateBody();
}

void Item::Update(float deltaTime)
{
	if (m_isBorn == false) return;
	if (m_AniCollected->isEndFrame())
	{
		m_isBorn = false;
		m_isUsed = false;
		return;
	}
	if (this->getBody()->IsActive()) Collising();

	if (m_isUsed == true)
	{
		m_CurrentAnimation = m_AniCollected;
		this->getBody()->SetActive(false);
		this->getBody()->SetAwake(false);
	}

	this->setPosition(World::ConvertToPixal(m_Body->GetPosition()));
	this->setRotation(180.f / b2_pi * m_Body->GetAngle());
	
	m_CurrentAnimation->Update(deltaTime);
	m_CurrentAnimation->setPosition(this->getPosition());
	m_CurrentAnimation->setRotation(this->getRotation());

}

void Item::Draw(sf::RenderWindow* window)
{
	if (m_isBorn==false) return;
	window->draw(*m_CurrentAnimation);
	//window->draw(*this);
}

void Item::Collising()
{
	for (b2ContactEdge* edge = m_Body->GetContactList(); edge; edge = edge->next)
	{
		if (edge->contact->GetFixtureA()->GetFilterData().categoryBits& CATEGORY_PLAYER)
		{
			this->setIsUsed(true);
			AttributeComponent* player = (AttributeComponent*)edge->contact->GetFixtureA()->GetBody()->GetUserData();
			player->HealHP(this->getExHp());
			if (isAllowThrowBomb()) player->AllowThrowBomb();
			player->UpDamgeBomb(this->getExDamgeBomb());
			player->UpDamgeBullet(this->getExDamgeBullet());
			player->CoolDownTimeThrowBomb(this->getTimeThrowBomb());
			player->CoolDownTimeThrowBullet(this->getTimeThrowBullet());
			player->UpVelocity(this->getExVelocity());
			player->DecreaseCoolDownTimeBomb(this->getCoolDownTimeBomb());
			player->UpPowerThrowBomb(this->getPowerThrowBomb());
			player->UpPowerThrowBullet(this->getPowerThrowBullet());
		}
	}
}

b2Body* Item::getBody()
{
	return m_Body;
}

void Item::Born()
{
	m_isBorn = true;
	this->getBody()->SetActive(true);
	this->getBody()->SetAwake(true);
	m_AniCollected->Reset();
	m_AniIdle->Reset();
	m_CurrentAnimation = m_AniIdle;
}

bool Item::isBorn()
{
	return m_isBorn;
}

void Item::Reset()
{
	this->setActive(false);
	m_isUsed = false;
	m_isBorn = false;
}

void Item::setBody(b2Body* newBody)
{
	m_Body = newBody;
}

void Item::CreateBody()
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(this->getPosition().x / SCALE, this->getPosition().y / SCALE);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;
	//BodyDef.gravityScale = 0.f;
	b2Body* Body = World::GetInstance()->GetWorld()->CreateBody(&BodyDef);

	b2CircleShape Shape;
	float radius = this->getRadius();
	Shape.m_radius = radius / SCALE;
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	FixtureDef.filter.categoryBits = CATEGORY_ITEM;
	FixtureDef.filter.maskBits = MASK_ITEM;
	Body->CreateFixture(&FixtureDef);
	m_Body = Body;
	Body->SetActive(false);
	Body->SetSleepingAllowed(false);
}
