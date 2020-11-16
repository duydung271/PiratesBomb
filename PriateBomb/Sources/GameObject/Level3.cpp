#include "Level3.h"

Level3::Level3()
{
}

Level3::~Level3()
{
	if (m_CreepSunDragonManager != nullptr)
	{
		delete m_CreepSunDragonManager;
	}
	m_CreepSunDragonManager = nullptr;

	m_Player = nullptr;
}

void Level3::Init(IPlayer* player)
{
	m_Player = player;
	m_CreepSunDragonManager = new CreepSunDragonManager();
	m_CreepSunDragonManager->Init();
}

void Level3::Update(float deltaTime)
{
	m_CreepSunDragonManager->setTarget(m_Player->GetAnimation()->getPosition());
	m_CreepSunDragonManager->Update(deltaTime);
}

void Level3::Draw(sf::RenderWindow* window)
{
	m_CreepSunDragonManager->Draw(window);
}

void Level3::Reset()
{
	m_CreepSunDragonManager->Reset();
}

bool Level3::isNeedNextLevel()
{
	//return true;
	if (DataGamePlay::GetInstance()->getNumSunDragonBorn() < 20) return false;
	else m_CreepSunDragonManager->setBornalbe(false);
	return DataGamePlay::GetInstance()->SunDragonBornEqualDead();
}
