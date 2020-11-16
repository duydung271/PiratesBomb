#include "ItemCoolDownTimeBomb.h"

ItemCoolDownTimeBomb::ItemCoolDownTimeBomb()
{
	this->setRadius(16.f);
	this->setOrigin(this->getRadius(), this->getRadius());
}

ItemCoolDownTimeBomb::~ItemCoolDownTimeBomb()
{
}

void ItemCoolDownTimeBomb::Init()
{
	Item::Init();
	m_AniIdle = new AnimationComponent();
	m_AniIdle->Init("Item_CoolDownTimeBomb");
	m_AniCollected = new AnimationComponent();
	m_AniCollected->Init("EffectIce");
	m_CurrentAnimation = m_AniIdle;

	//setAttribute
	this->setCoolDownTimeBomb(Item_CoolDownTimeBomb);
}

void ItemCoolDownTimeBomb::Update(float deltaTime)
{
	Item::Update(deltaTime);
}

void ItemCoolDownTimeBomb::Draw(sf::RenderWindow* window)
{
	Item::Draw(window);
}
