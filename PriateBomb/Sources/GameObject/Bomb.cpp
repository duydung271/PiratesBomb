#include "Bomb.h"
#include "BombOffState.h"
#include "ExplosionState.h"
#include "BombOnState.h"


Bomb::Bomb()
{
	this->setPosition(200.f, 200.f);
	this->setRadius(16.f);
	this->setOrigin(getRadius(), getRadius());
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineColor(sf::Color::Red);
	this->setOutlineThickness(1.f);
	m_CoolDownTime = 10.f;
	m_CurrentAction = STATE_BOMBOFF;
	m_NextState = STATE_NULL;

	m_BombOffState = new BombOffState(this);
	m_ExplosionState = new ExpolsionState(this);
	m_BombOnState = new BombOnState(this);

	m_CurrentState = m_BombOffState;
}

Bomb::~Bomb()
{
	if (m_Animation != nullptr)
	{
		delete m_Animation;
		m_Animation = nullptr;
	}
	if (m_BombOffState != nullptr)
	{
		delete m_BombOffState;
		m_BombOffState = nullptr;
	}
	if (m_BombOnState != nullptr)
	{
		delete m_BombOnState;
		m_BombOnState = nullptr;
	}
	if (m_ExplosionState != nullptr)
	{
		delete m_ExplosionState;
		m_ExplosionState = nullptr;
	}
	m_CurrentState = nullptr;

	if (m_Attribute != nullptr)
	{
		delete m_Attribute;
	}
	m_Attribute = nullptr;
}

void Bomb::Init()
{
	m_Animation = new AnimationComponent();
	m_Animation->Init("Bomb");
	m_Animation->setState((int)m_CurrentAction);

	sf::Vector2f origin((sf::Vector2f)m_Animation->getSize() * 0.5f);
	m_Animation->setOrigin(origin.x,origin.y+16.f);

	sf::Vector2f pos(getPosition());
	float radius = getRadius();

	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(pos.x / SCALE, pos.y / SCALE);
	BodyDef.type = b2_dynamicBody;
	b2Body* Body = World::GetInstance()->GetWorld()->CreateBody(&BodyDef);

	b2CircleShape Shape;
	Shape.m_radius = radius / SCALE;
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.restitution = 0.3f;
	FixtureDef.shape = &Shape;
	FixtureDef.filter.categoryBits = CATEGORY_BOMB;
	FixtureDef.filter.maskBits = MASK_BOMB;
	Body->CreateFixture(&FixtureDef);
	Body->SetActive(false);
	Body->SetAwake(false);

	setBody(Body);
	m_ExplosionState->Init();
	m_Attribute = new AttributeComponent();
	m_Attribute->setHP(1);
	m_Attribute->setDamge(100);
	
	m_Body->SetUserData(m_Attribute);
}

void Bomb::Update(float deltaTime)
{
	if (m_Attribute->isDead())
	{
		setNextState(STATE_EXPLOSION);
		m_Attribute->setHP(1);
	}
	SetAction(); 
	if (!isActive()) return;
	m_CurrentState->Update(deltaTime);
	this->setPosition(World::ConvertToPixal(getBody()->GetPosition()));
	this->setRotation(180 / b2_pi * getBody()->GetAngle());

	m_Animation->Update(deltaTime);
	m_Animation->setPosition(this->getPosition().x, this->getPosition().y);
	m_Animation->setRotation(this->getRotation());
}

void Bomb::Draw(sf::RenderWindow* window)
{
	if (!isActive()) return;
	window->draw(*m_Animation);
	//window->draw(*this);
}

AnimationComponent* Bomb::GetAnimation()
{
	return m_Animation;;
}

void Bomb::setNextState(STATE newState)
{
	m_NextState = newState;
}

void Bomb::SetAction()
{
	if (m_NextState == STATE_NULL) return;
	m_CurrentAction = m_NextState;
	switch (m_CurrentAction)
	{
	case STATE_BOMBOFF:
		SetState(m_BombOffState);
		break;
	case STATE_BOMBON:
		SetState(m_BombOnState);
		break;
	case STATE_EXPLOSION:
		SetState(m_ExplosionState);
		break;
	default:
		break;
	}
	m_Animation->setState(m_CurrentAction);
	if (m_CurrentAction == STATE_STOP) setActive(false);
	m_NextState = STATE_NULL;
}

void Bomb::SetState(IBombState* newState)
{
	m_CurrentState = newState;
}

b2Body* Bomb::GetBody()
{
	return Entity::getBody();
}

void Bomb::setDamge(float damge)
{
	m_Attribute->setDamge(damge);
}

float Bomb::getCoolDownTime()
{
	return m_CoolDownTime;
}

void Bomb::setCoolDownTime(float time)
{
	m_CoolDownTime = time;
}

