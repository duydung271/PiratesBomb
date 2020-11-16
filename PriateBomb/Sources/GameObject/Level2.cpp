#include "Level2.h"

Level2::Level2()
{
}

Level2::~Level2()
{
	if (m_CreepBatManager != nullptr)
	{
		delete m_CreepBatManager;
	}
	m_CreepBatManager = nullptr;

	if (m_CreepBeeManager != nullptr)
	{
		delete m_CreepBeeManager;
	}
	m_CreepBeeManager = nullptr;

	if (m_CreepBlueBirdManager != nullptr)
	{
		delete m_CreepBlueBirdManager;
	}
	m_CreepBlueBirdManager = nullptr;

	m_Player = nullptr;
}

void Level2::Init(IPlayer* player)
{
	m_Player = player;
	m_CreepBatManager = new CreepBatManager();
	m_CreepBatManager->Init();
	m_CreepBeeManager = new CreepBeeManager();
	m_CreepBeeManager->Init();
	m_CreepBlueBirdManager = new CreepBlueBirdManager();
	m_CreepBlueBirdManager->Init();
}

void Level2::Update(float deltaTime)
{
	m_CreepBatManager->setTarget(m_Player->GetAnimation()->getPosition());
	m_CreepBatManager->Update(deltaTime);

	m_CreepBeeManager->setTarget(m_Player->GetAnimation()->getPosition());
	m_CreepBeeManager->Update(deltaTime);

	m_CreepBlueBirdManager->setTarget(m_Player->GetAnimation()->getPosition());
	m_CreepBlueBirdManager->Update(deltaTime);
}

void Level2::Draw(sf::RenderWindow* window)
{
	m_CreepBatManager->Draw(window);
	m_CreepBeeManager->Draw(window);
	m_CreepBlueBirdManager->Draw(window);
}

void Level2::Reset()
{
	m_CreepBatManager->Reset();
	m_CreepBeeManager->Reset();
	m_CreepBlueBirdManager->Reset();
}

bool Level2::isNeedNextLevel()
{
	//return true;
	if (DataGamePlay::GetInstance()->getNumBeeBorn() < 40) return false;
	else if (DataGamePlay::GetInstance()->getNumBatBorn() < 40) return false;
	else if (DataGamePlay::GetInstance()->getNumBlueBirdBorn() < 40) return false;
	else
	{
		m_CreepBeeManager->setBornalbe(false);
		m_CreepBatManager->setBornalbe(false);
		m_CreepBlueBirdManager->setBornalbe(false);
	}
	return DataGamePlay::GetInstance()->BeeBornEqualDead()
		&&DataGamePlay::GetInstance()->BatBornEqualDead()
			&&DataGamePlay::GetInstance()->BlueBirdBornEqualDead();
}
