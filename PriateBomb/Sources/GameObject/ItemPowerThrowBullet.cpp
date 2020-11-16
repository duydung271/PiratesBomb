#include "ItemPowerThrowBullet.h"

ItemPowerThrowBullet::ItemPowerThrowBullet()
{
	this->setRadius(16.f);
	this->setOrigin(this->getRadius(), this->getRadius());
}

ItemPowerThrowBullet::~ItemPowerThrowBullet()
{
}

void ItemPowerThrowBullet::Init()
{
	Item::Init();
	m_AniIdle = new AnimationComponent();
	m_AniIdle->Init("Item_PowerThrowBullet");
	m_AniCollected = new AnimationComponent();
	m_AniCollected->Init("EffectMagic");
	m_CurrentAnimation = m_AniIdle;

	//setAttribute
	this->setPowerThrowBullet(Item_PowerThrowBullet);

}

void ItemPowerThrowBullet::Update(float deltaTime)
{
	Item::Update(deltaTime);
}

void ItemPowerThrowBullet::Draw(sf::RenderWindow* window)
{
	Item::Draw(window);
}
