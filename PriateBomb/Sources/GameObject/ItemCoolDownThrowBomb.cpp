#include "ItemCoolDownThrowBomb.h"

ItemCoolDownThrowBomb::ItemCoolDownThrowBomb()
{
	this->setRadius(16.f);
	this->setOrigin(this->getRadius(), this->getRadius());
}

ItemCoolDownThrowBomb::~ItemCoolDownThrowBomb()
{
}

void ItemCoolDownThrowBomb::Init()
{
	Item::Init();
	m_AniIdle = new AnimationComponent();
	m_AniIdle->Init("Item_CoolDownThrowBomb");
	m_AniCollected = new AnimationComponent();
	m_AniCollected->Init("EffectFireCast");
	m_CurrentAnimation = m_AniIdle;

	//setAttribute
	this->setTimeThrowBomb(Item_TimeThrowBomb);
}

void ItemCoolDownThrowBomb::Update(float deltaTime)
{
	Item::Update(deltaTime);
}

void ItemCoolDownThrowBomb::Draw(sf::RenderWindow* window)
{
	Item::Draw(window);
}
