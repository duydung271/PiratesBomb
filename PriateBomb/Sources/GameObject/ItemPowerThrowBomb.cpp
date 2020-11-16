#include "ItemPowerThrowBomb.h"

ItemPowerThrowBomb::ItemPowerThrowBomb()
{
	this->setRadius(16.f);
	this->setOrigin(this->getRadius(), this->getRadius());
}

ItemPowerThrowBomb::~ItemPowerThrowBomb()
{
}

void ItemPowerThrowBomb::Init()
{
	Item::Init();
	m_AniIdle = new AnimationComponent();
	m_AniIdle->Init("Item_PowerThrowBomb");
	m_AniCollected = new AnimationComponent();
	m_AniCollected->Init("EffectPoison");
	m_CurrentAnimation = m_AniIdle;

	//setAttribute
	this->setPowerThrowBomb(Item_PowerThrowBomb);

}

void ItemPowerThrowBomb::Update(float deltaTime)
{
	Item::Update(deltaTime);
}

void ItemPowerThrowBomb::Draw(sf::RenderWindow* window)
{
	Item::Draw(window);
}
