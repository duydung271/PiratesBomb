#include "ItemJump.h"

ItemJump::ItemJump()
{
	this->setRadius(16.f);
	this->setOrigin(this->getRadius(), this->getRadius());
}

ItemJump::~ItemJump()
{
}

void ItemJump::Init()
{
	Item::Init();
	m_AniIdle = new AnimationComponent();
	m_AniIdle->Init("Item_Jump");
	m_AniCollected = new AnimationComponent();
	m_AniCollected->Init("EffectIce");
	m_CurrentAnimation = m_AniIdle;

	//setAttribute
	this->setExVelocity(sf::Vector2f(0.f, Item_Jump));

}

void ItemJump::Update(float deltaTime)
{
	Item::Update(deltaTime);
}

void ItemJump::Draw(sf::RenderWindow* window)
{
	Item::Draw(window);
}
