#include "ItemDamgeBullet.h"

ItemDamgeBullet::ItemDamgeBullet()
{
	this->setRadius(16.f);
	this->setOrigin(this->getRadius(), this->getRadius());
}

ItemDamgeBullet::~ItemDamgeBullet()
{
}

void ItemDamgeBullet::Init()
{
	Item::Init();
	m_AniIdle = new AnimationComponent();
	m_AniIdle->Init("Item_ExBulletDamge");
	m_AniCollected = new AnimationComponent();
	m_AniCollected->Init("EffectIce");
	m_CurrentAnimation = m_AniIdle;

	//setAttribute
	this->setExDamegeBullet(Item_DamgeBullet);
}

void ItemDamgeBullet::Update(float deltaTime)
{
	Item::Update(deltaTime);
}

void ItemDamgeBullet::Draw(sf::RenderWindow* window)
{
	Item::Draw(window);
}
