#include "CreepBee.h"

CreepBee::CreepBee()
{
	this->m_timeChangeTarger = 0.5f;
}

CreepBee::~CreepBee()
{
}

void CreepBee::Init()
{
	BaseCreep::Init();
	m_AniHit = new AnimationComponent();
	m_AniHit->Init("BeeHit");

	m_AniRun = new AnimationComponent();
	m_AniRun->Init("BeeRun");
	m_CurrentAni = m_AniRun;

	m_Attribute->setDamge(3);
	m_Attribute->setMaxHP(20);
	
}

void CreepBee::Update(float deltaTime)
{
	BaseCreep::Update(deltaTime);

}
