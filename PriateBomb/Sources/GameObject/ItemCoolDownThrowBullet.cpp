#include "ItemCoolDownThrowBullet.h"

ItemCoolDownThrowBullet::ItemCoolDownThrowBullet()
{
	this->setRadius(16.f);
	this->setOrigin(this->getRadius(), this->getRadius());
}

ItemCoolDownThrowBullet::~ItemCoolDownThrowBullet()
{
}

void ItemCoolDownThrowBullet::Init()
{
	Item::Init();
	m_AniIdle = new AnimationComponent();
	m_AniIdle->Init("Item_CoolDownThrowBullet");
	m_AniCollected = new AnimationComponent();
	m_AniCollected->Init("EffectFireCast");
	m_CurrentAnimation = m_AniIdle;

	//setAttribute
	this->setTimeThrowBullet(Item_TimeThrowBullet);
}

void ItemCoolDownThrowBullet::Update(float deltaTime)
{
	Item::Update(deltaTime);
}

void ItemCoolDownThrowBullet::Draw(sf::RenderWindow* window)
{
	Item::Draw(window);
}
