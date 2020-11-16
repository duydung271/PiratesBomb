#include "CreepBullet.h"

CreepBullet::CreepBullet()
{
	this->setRadius(30);
	this->setOrigin(this->getRadius(), this->getRadius());
	m_Speed = 300.f;
}

CreepBullet::~CreepBullet()
{
}

void CreepBullet::Init()
{
	
	m_Attribute = new AttributeComponent();
	m_Attribute->setDamge(20);
	m_Attribute->setHP(100);
	m_Attribute->setMaxHP(100);
	createBody();
	getBody()->SetUserData(m_Attribute);

	m_HearBar = new HeartBar();
	m_HearBar->setAttribute(m_Attribute);
	m_HearBar->setEntity(this);
	m_HearBar->Init();

	m_Active = true;
	m_AniHit = new AnimationComponent();
	m_AniHit->Init("FireSkullHit");

	m_AniRun = new AnimationComponent();
	m_AniRun->Init("FireSkullRun");
	m_CurrentAni = m_AniRun;
	m_isCalled = true;
}

void CreepBullet::Update(float deltaTime)
{
	if (m_Attribute->isDead())
	{
		
		m_Body->SetActive(false);
		m_Body->SetAwake(false);
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
		if (m_Attribute->isDead()) m_Active = false;
	}
	m_CurrentAni->Update(deltaTime);
	//if (isCollisionWithGround()) m_isCalled = true;
	if (this->getPosition().x <= -100 || this->getPosition().x >= screenWidth + 100) m_isCalled = true;
	if (this->getPosition().y <= -100 || this->getPosition().y >= screenHeight + 100) m_isCalled = true;
	if (m_isCalled==true) {
		m_MovingDirect.Update(this->getPosition(), m_NextPoint);
		sf::Vector2f velocity;
		velocity = m_MovingDirect.getVectorUnit() * m_Speed;
		m_Body->SetLinearVelocity(World::ConvertToPM(velocity));
		m_isCalled = false;
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

void CreepBullet::Call()
{
	m_isCalled = true;
}

bool CreepBullet::isCollisionWithGround()
{
	for (b2ContactEdge* edge = m_Body->GetContactList(); edge; edge = edge->next)
	{
		if (edge->contact->GetFixtureA()->GetType() == b2_staticBody) return true;
		if (edge->contact->GetFixtureB()->GetType() == b2_staticBody) return true;
	}
	return false;
}

void CreepBullet::createBody()
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
	FixtureDef.filter.categoryBits = CATEGORY_BULLET_BOSS;
	FixtureDef.filter.maskBits = MASK_BULLET_BOSS;
	Body->CreateFixture(&FixtureDef);
	m_Body = Body;
	Body->SetActive(false);
	Body->SetSleepingAllowed(false);
}
