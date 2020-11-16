#include "CreepSunDragon.h"

CreepSunDragon::CreepSunDragon()
{
	this->m_Speed = 300.f;
	this->setRadius(30);
	this->setOrigin(this->getRadius(), this->getRadius());
	m_AniPosOffSet = sf::Vector2f(-20, -10);
}

CreepSunDragon::~CreepSunDragon()
{
}

void CreepSunDragon::Init()
{
	BaseCreep::Init();
	m_AniHit = new AnimationComponent();
	m_AniHit->Init("SunDragonHit");

	m_AniRun = new AnimationComponent();
	m_AniRun->Init("SunDragonRun");
	m_CurrentAni = m_AniRun;

	m_HearBar->setOffSet(sf::Vector2f(0, -10));
	m_Attribute->setDamge(20);
	m_Attribute->setMaxHP(100);


}

void CreepSunDragon::Update(float deltaTime)
{
	sf::Vector2f pos = m_CurrentAni->getPosition();
	if (m_CurrentAni->getDirect() == DIRECT::DIRECT_RIGHT)
	{
		pos.x -= m_AniPosOffSet.x;
	}
	else pos.x += m_AniPosOffSet.x;
	pos.y += m_AniPosOffSet.y;
	m_CurrentAni->setPosition(pos);

	BaseCreep::Update(deltaTime);

}
