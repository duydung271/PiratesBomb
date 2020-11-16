#include "CreepBat.h"

CreepBat::CreepBat()
{
}

CreepBat::~CreepBat()
{
}

void CreepBat::Init()
{
	BaseCreep::Init();
	m_AniHit = new AnimationComponent();
	m_AniHit->Init("BatHit");

	m_AniRun = new AnimationComponent();
	m_AniRun->Init("BatFlying");
	m_CurrentAni = m_AniRun;

	m_Attribute->setDamge(5);
	m_Attribute->setMaxHP(30);

}

void CreepBat::Update(float deltaTime)
{
	BaseCreep::Update(deltaTime);

}
