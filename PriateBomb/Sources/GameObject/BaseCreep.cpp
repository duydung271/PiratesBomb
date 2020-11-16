#include "BaseCreep.h"

BaseCreep::BaseCreep()
{
	m_isMovingToNext = false;
	m_NextPoint = sf::Vector2f(0, 0);
	m_timeChangeTarger = 3.f;
	m_currentTime = 0.f;
	m_Speed = 100.f;
	m_CurrentAction = RUN;
	m_NextAction = STATE_NULL;
	//this->setSize(sf::Vector2f(26, 26));
	//this->setOrigin(this->getSize() * 0.5f);
	this->setRadius(12);
	this->setOrigin(this->getRadius(), this->getRadius());
	this->setPosition(500, 100);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineColor(sf::Color::Red);
	this->setOutlineThickness(1.f);
	m_NextPoint = this->getPosition();
	m_wasCreatedItem = false;

}

BaseCreep::~BaseCreep()
{
	if (m_AniHit != nullptr)
	{
		delete m_AniHit;
	}
	m_AniHit = nullptr;

	if (m_AniRun != nullptr)
	{
		delete m_AniHit;
	}
	m_AniHit = nullptr;

	m_CurrentAni = nullptr;

	if (m_HearBar != nullptr)
	{
		delete m_HearBar;
	}
	m_HearBar = nullptr;

	if (m_Attribute != nullptr)
	{
		delete m_Attribute;
	}
	m_Attribute = nullptr;

}


void BaseCreep::setTarget(sf::Vector2f target)
{
	m_NextPoint = target;
}

void BaseCreep::Init()
{

	CreateBody();

	m_Attribute = new AttributeComponent();
	m_Attribute->setMaxHP(100);
	m_Attribute->setDamge(1);
	getBody()->SetUserData(m_Attribute);

	m_HearBar = new HeartBar();
	m_HearBar->setAttribute(m_Attribute);
	m_HearBar->setEntity(this);
	m_HearBar->Init();

	m_Active = true;
}

void BaseCreep::Update(float deltaTime)
{
	
	if (m_Attribute->isDead())
	{
		m_Body->SetActive(false);
		m_Body->SetAwake(false);
		if (m_wasCreatedItem == false) {
			int x = rand() % 100;
			CountDead();
			if (x<5) ItemManager::GetInstance()->BornItem(this->getPosition());
			m_wasCreatedItem = true;
		}
	}
	if (m_Attribute->isPush() == true)
	{
		b2Vec2 v = m_Body->GetLinearVelocity();
		v *= -1;
		m_Body->SetLinearVelocity(v);
		m_Attribute->setIsPush(false);
	}
	m_Attribute->Update(deltaTime);
	if (m_Active == false) return;
	if (m_Attribute->isHit())
	{
		m_CurrentAni = m_AniHit;
	}
	if (m_AniHit->isEndFrame())
	{
		m_AniHit->Reset();
		m_CurrentAni = m_AniRun;
		if(m_Attribute->isDead()) m_Active = false;
	}
	m_currentTime += deltaTime;
	m_CurrentAni->Update(deltaTime);
	if (m_currentTime >= m_timeChangeTarger) {
		m_MovingDirect.Update(this->getPosition(), m_NextPoint);
		m_currentTime -= m_timeChangeTarger;

		sf::Vector2f velocity;
		velocity = m_MovingDirect.getVectorUnit() * m_Speed;
		m_Body->SetLinearVelocity(World::ConvertToPM(velocity));
	}
	
	this->setPosition(World::ConvertToPixal(getBody()->GetPosition()));
	this->setRotation(180 / b2_pi * getBody()->GetAngle());
	if (m_NextPoint.x > getPosition().x)
	{
		m_CurrentAni->setDirect(DIRECT::DIRECT_LEFT);
	}
	else m_CurrentAni->setDirect(DIRECT::DIRECT_RIGHT);
	m_CurrentAni->setPosition(this->getPosition());
	m_CurrentAni->setRotation(this->getRotation());
	m_HearBar->Update(deltaTime);

}

void BaseCreep::Draw(sf::RenderWindow* window)
{
	if (m_Active == false) return;
	window->draw(*m_CurrentAni);
	//window->draw(*this);
	m_HearBar->Draw(window);
}

void BaseCreep::setNextState(BASE_CREEP_STATE newState)
{
	m_NextAction = newState;
}

void BaseCreep::performState()
{
}

void BaseCreep::Reset()
{
	m_Attribute->setHP(m_Attribute->getMaxHP());
}

void BaseCreep::Awake()
{
	CountBorn();
	Reset();
	setActive(true);
	getBody()->SetActive(true);
	getBody()->SetAwake(true);
	getBody()->SetTransform(World::ConvertToPM(sf::Vector2f((rand() % 8) * 200, ((rand() % 2) + 1) * -100)), 0);
	m_wasCreatedItem = false;
}

void BaseCreep::ResetAll()
{
	Reset();
	setActive(false);
	getBody()->SetActive(false);
	getBody()->SetAwake(false);
	m_wasCreatedItem = false;
}

void BaseCreep::CreateBody()
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(this->getPosition().x / SCALE, this->getPosition().y / SCALE);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;
	BodyDef.gravityScale = 0.f;
	b2Body* Body = World::GetInstance()->GetWorld()->CreateBody(&BodyDef);

	b2CircleShape Shape;
	float radius = this->getRadius();
	Shape.m_radius = radius / SCALE;
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	FixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	FixtureDef.filter.maskBits = MASK_MONSTER;
	Body->CreateFixture(&FixtureDef);
	m_Body = Body;
	Body->SetActive(false);
	Body->SetSleepingAllowed(false);
}
