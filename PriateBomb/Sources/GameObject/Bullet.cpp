#include "Bullet.h"
#include "FireState.h"
#include "ExplositionState.h"

Bullet::Bullet()
{
	this->setPosition(200.f, 200.f);
	this->setRadius(3.f);
	this->setOrigin(getRadius(), getRadius());
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineColor(sf::Color::Red);
	this->setOutlineThickness(1.f);

	m_explositionState = new ExplositionState(this);
	m_fireState = new FireState(this);
	m_currentState = m_fireState;
	m_currentAction = STATE_FIRE;
	m_NextAction = STATE_NULL;
	
}

Bullet::~Bullet()
{
	if (m_fireState != nullptr)
	{
		delete m_fireState;
	}
	m_fireState = nullptr;

	if (m_explositionState != nullptr)
	{
		delete m_explositionState;
	}
	m_explositionState = nullptr;

	m_currentState = nullptr;

	if (m_Attribute != nullptr)
	{
		delete m_Attribute;
	}
	m_Attribute = nullptr;
}

void Bullet::Init()
{
	sf::Vector2f pos(getPosition());
	float radius = getRadius();

	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(pos.x / SCALE, pos.y / SCALE);
	BodyDef.type = b2_dynamicBody;
	BodyDef.gravityScale = 0.f;
	b2Body* Body = World::GetInstance()->GetWorld()->CreateBody(&BodyDef);

	b2CircleShape Shape;
	Shape.m_radius = radius / SCALE;
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	FixtureDef.filter.categoryBits = CATEGORY_BULLET;
	FixtureDef.filter.maskBits = MASK_BULLET;
	Body->CreateFixture(&FixtureDef);

	setBody(Body);
	Body->SetActive(false);
	Body->SetSleepingAllowed(false);
	setActive(false);
	Body->SetBullet(true);

	m_fireState->Init();
	m_explositionState->Init();
	m_Attribute = new AttributeComponent();
	m_Attribute->setDamge(m_Attribute->getDamge());
	m_Body->SetUserData(m_Attribute);

}

void Bullet::Update(float deltaTime)
{
	performAction();
	this->setPosition(World::ConvertToPixal(getBody()->GetPosition()));
	this->setRotation(180 / b2_pi * getBody()->GetAngle());

	m_currentState->setTransform(getPosition(), getRotation());
	m_currentState->Update(deltaTime);
}

void Bullet::Draw(sf::RenderWindow* window)
{
	m_currentState->Draw(window);
	//window->draw(*this);
}

void Bullet::setNextState(STATE_BULLET newState)
{
	m_NextAction = newState;
}

void Bullet::performAction()
{
	if (m_NextAction == STATE_BULLET::STATE_NULL) return;
	m_currentAction = m_NextAction;
	switch (m_currentAction)
	{
	case STATE_FIRE:
		m_currentState = m_fireState;
		break;
	case STATE_EXPLORSION:
		m_currentState = m_explositionState;
		break;
	default:
		break;
	}
	m_NextAction = STATE_NULL;
}

b2Body* Bullet::getBody()
{
	return Entity::getBody();
}

bool Bullet::isCollision()
{
	if (getBody()->GetContactList() == NULL)
	{
		return false;
	}
	return true;
}

Entity* Bullet::getEntity()
{
	return this;
}

void Bullet::setDamge(float damge)
{
	m_Attribute->setDamge(damge);
}
