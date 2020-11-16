#include "Boss.h"

Boss::Boss()
{
	this->setRadius(50);
	this->setOrigin(this->getRadius(), this->getRadius());
	m_timeChangeTarger=10.f;
	m_Speed = 300;
}

Boss::~Boss()
{
	if (m_BulletManager != nullptr)
	{
		delete m_BulletManager;
	}
	m_BulletManager = nullptr;
	if (m_AniAttack != nullptr)
	{
		delete m_BulletManager;
	}
	m_AniAttack = nullptr;
}

void Boss::Init()
{
	CreateBodyBoss();
	m_Attribute = new AttributeComponent();
	m_Attribute->setMaxHP(50000);
	m_Attribute->setHP(50000);
	getBody()->SetUserData(m_Attribute);
	m_Attribute->setDamge(30);//Damge

	m_HearBar = new HeartBar();
	m_HearBar->setAttribute(m_Attribute);
	m_HearBar->setEntity(this);
	m_HearBar->Init();
	m_HearBar->setSize(sf::Vector2f(200, 15));
	m_HearBar->setOffSet(sf::Vector2f(-40, -130));

	m_Active = true;

	m_AniHit = new AnimationComponent();
	m_AniHit->Init("DemonHit");
	m_AniHit->setScale(2.f, 2.f);
	m_AniRun = new AnimationComponent();
	m_AniRun->Init("DemonRun");
	m_AniRun->setScale(2.f, 2.f);
	m_AniAttack = new AnimationComponent();
	m_AniAttack->Init("DemonAttack");
	m_AniAttack->setScale(2.f, 2.f);
	m_CurrentAni = m_AniAttack;

	m_BulletManager = new BulletBossManager();
	m_BulletManager->Init();
	m_Intro = true;
	m_currentTime = 0.f;
}

void Boss::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_Intro == true)
	{
		b2Vec2 v (0.f,-100.f / SCALE);
		m_Body->SetLinearVelocity(v);
	}
	if (m_currentTime > 10.f)
	{
		m_Intro = false;
		m_currentTime = 0.f;
	}
	if (m_AniAttack->isEndFrame())
	{
		m_CurrentAni = m_AniRun;
		m_AniRun->Reset();
		m_AniAttack->Reset();
		m_BulletManager->setCallBack(true);
	}
	m_BulletManager->setPositionAppear(this->getPosition());
	if (m_Intro==false)
	{
		m_BulletManager->setTarget(m_NextPoint);
		m_BulletManager->Update(deltaTime);
	}
	if (m_BulletManager->isStartAniAttack())
	{
		m_CurrentAni = m_AniAttack;
	}
	//Khong cho Boss bay ra khoi man hinh
	bool checkConert = false;
	if (this->getPosition().y > screenHeight - 100) checkConert = true;
	if (checkConert)
	{
		b2Vec2 v = m_Body->GetLinearVelocity();
		v.y = -abs(v.y);
		m_Body->SetLinearVelocity(v);
		checkConert = false;
	}

	if (this->getPosition().y <= 100.f) checkConert = true;
	if (checkConert == true)
	{
		b2Vec2 v(0, 10.f/SCALE);
		m_Body->SetLinearVelocity(v);
		checkConert = false;
	}

	if (this->getPosition().x <= 100.f) checkConert = true;
	if (checkConert == true)
	{
		b2Vec2 v(10.f / SCALE, 0);
		m_Body->SetLinearVelocity(v);
		checkConert = false;
	}

	if (this->getPosition().x >= screenWidth -100.f) checkConert = true;
	if (checkConert == true)
	{
		b2Vec2 v(-10.f / SCALE, 0);
		m_Body->SetLinearVelocity(v);
		checkConert = false;
	}


	BaseCreep::Update(deltaTime);

	
	
}

void Boss::Draw(sf::RenderWindow* window)
{
	BaseCreep::Draw(window);
	m_BulletManager->Draw(window);
}

void Boss::CreateBodyBoss()
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
	FixtureDef.filter.categoryBits = CATEGORY_BOSS;
	FixtureDef.filter.maskBits = MASK_BOSS;
	Body->CreateFixture(&FixtureDef);
	m_Body = Body;
}
