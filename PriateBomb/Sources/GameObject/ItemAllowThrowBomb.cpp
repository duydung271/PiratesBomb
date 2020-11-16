#include "ItemAllowThrowBomb.h"

ItemAllowThrowBomb::ItemAllowThrowBomb()
{
	this->setRadius(16.f);
	this->setOrigin(this->getRadius(), this->getRadius());
}

ItemAllowThrowBomb::~ItemAllowThrowBomb()
{
}

void ItemAllowThrowBomb::Init()
{
	Item::Init();
	m_AniIdle = new AnimationComponent();
	m_AniIdle->Init("Item_AllowThrowBomb");
	m_AniCollected = new AnimationComponent();
	m_AniCollected->Init("EffectLightCast");
	m_CurrentAnimation = m_AniIdle;

	//setAttribute
	this->setAllowThrowBomb(Item_isAllowThrowBomb);
}

void ItemAllowThrowBomb::Update(float deltaTime)
{
	Item::Update(deltaTime);
}

void ItemAllowThrowBomb::Draw(sf::RenderWindow* window)
{
	Item::Draw(window);
}
