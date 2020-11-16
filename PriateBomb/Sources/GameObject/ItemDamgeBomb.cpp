#include "ItemDamgeBomb.h"

ItemDamgeBomb::ItemDamgeBomb()
{
	this->setRadius(16.f);
	this->setOrigin(this->getRadius(), this->getRadius());
}

ItemDamgeBomb::~ItemDamgeBomb()
{
}

void ItemDamgeBomb::Init()
{
	Item::Init();
	m_AniIdle = new AnimationComponent();
	m_AniIdle->Init("Item_DamgeBomb");
	m_AniCollected = new AnimationComponent();
	m_AniCollected->Init("EffectExplosion");
	m_CurrentAnimation = m_AniIdle;

	//setAttribute
	this->setExDamgeBomb(Item_DamgeBomb);
}

void ItemDamgeBomb::Update(float deltaTime)
{
	Item::Update(deltaTime);
}

void ItemDamgeBomb::Draw(sf::RenderWindow* window)
{
	Item::Draw(window);
}
