#include "ItemSpeed.h"

ItemSpeed::ItemSpeed()
{
	this->setRadius(16.f);
	this->setOrigin(this->getRadius(), this->getRadius());
}

ItemSpeed::~ItemSpeed()
{
}

void ItemSpeed::Init()
{
	Item::Init();
	m_AniIdle = new AnimationComponent();
	m_AniIdle->Init("Item_Speed");
	m_AniCollected = new AnimationComponent();
	m_AniCollected->Init("EffectIce");
	m_CurrentAnimation = m_AniIdle;

	//setAttribute
	this->setExVelocity(sf::Vector2f(Item_Speed, 0.f));

}

void ItemSpeed::Update(float deltaTime)
{
	Item::Update(deltaTime);
}

void ItemSpeed::Draw(sf::RenderWindow* window)
{
	Item::Draw(window);
}
