#include "CreepBlueBird.h"

CreepBlueBird::CreepBlueBird()
{
	this->m_Speed = 250.f;
}

CreepBlueBird::~CreepBlueBird()
{
}

void CreepBlueBird::Init()
{
	BaseCreep::Init();
	m_AniHit = new AnimationComponent();
	m_AniHit->Init("BlueBirdHit");

	m_AniRun = new AnimationComponent();
	m_AniRun->Init("BlueBirdFlying");
	m_CurrentAni = m_AniRun;

	m_Attribute->setDamge(3);
	m_Attribute->setMaxHP(30);



}

void CreepBlueBird::Update(float deltaTime)
{
	BaseCreep::Update(deltaTime);

}
