#include "Level1.h"

Level1::Level1()
{
}

Level1::~Level1()
{
	if (m_CreepBatManager != nullptr)
	{
		delete m_CreepBatManager;
	}
	m_CreepBatManager = nullptr;
	m_Player = nullptr;
}

void Level1::Init(IPlayer* player)
{
	m_Player = player;
	m_CreepBatManager = new CreepBatManager();
	m_CreepBatManager->Init();
}

void Level1::Update(float deltaTime)
{
	m_CreepBatManager->setTarget(m_Player->GetAnimation()->getPosition());
	m_CreepBatManager->Update(deltaTime);
}

void Level1::Draw(sf::RenderWindow* window)
{
	m_CreepBatManager->Draw(window);
}

void Level1::Reset()
{
	m_CreepBatManager->Reset();
}

bool Level1::isNeedNextLevel()
{
	//return true;
	if (DataGamePlay::GetInstance()->getNumBatBorn() < 40) return false;
	else m_CreepBatManager->setBornalbe(false);
	return DataGamePlay::GetInstance()->BatBornEqualDead();
	
}
