#include "ItemHeart.h"

ItemHeart::ItemHeart()
{
	this->setRadius(16.f);
	this->setOrigin(this->getRadius(), this->getRadius());
}

ItemHeart::~ItemHeart()
{
}

void ItemHeart::Init()
{
	Item::Init();
	m_AniIdle = new AnimationComponent();
	m_AniIdle->Init("HeartIdle");
	m_AniCollected = new AnimationComponent();
	m_AniCollected->Init("HeartCollected");
	m_CurrentAnimation = m_AniIdle;

	//setAttribute
	this->setExHp(Item_HP);
}

void ItemHeart::Update(float deltaTime)
{
	Item::Update(deltaTime);
}

void ItemHeart::Draw(sf::RenderWindow* window)
{
	Item::Draw(window);
}
