#include "CreepSkull.h"

CreepSkull::CreepSkull()
{
	this->m_Speed = 300.f;
	this->setRadius(20);
	this->setOrigin(this->getRadius(), this->getRadius());
}

CreepSkull::~CreepSkull()
{
}

void CreepSkull::Init()
{
	BaseCreep::Init();
	m_AniHit = new AnimationComponent();
	m_AniHit->Init("SkullHit");

	m_AniRun = new AnimationComponent();
	m_AniRun->Init("SkullRun");
	m_CurrentAni = m_AniRun;
	m_HearBar->setOffSet(sf::Vector2f(0,-10));

	m_Attribute->setDamge(10);
	m_Attribute->setMaxHP(50);

}

void CreepSkull::Update(float deltaTime)
{
	BaseCreep::Update(deltaTime);

}
