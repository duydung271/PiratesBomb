#include "Level4.h"

Level4::Level4()
{
}

Level4::~Level4()
{
	if (m_CreepSkullManager != nullptr)
	{
		delete m_CreepSkullManager;
	}
	m_CreepSkullManager = nullptr;

	m_Player = nullptr;
}

void Level4::Init(IPlayer* player)
{
	m_Player = player;
	m_CreepSkullManager = new CreepSkullManager();
	m_CreepSkullManager->Init();
	m_Boss = new Boss();
	m_Boss->Init();
	m_Boss->Awake();
}

void Level4::Update(float deltaTime)
{
	m_CreepSkullManager->setTarget(m_Player->GetAnimation()->getPosition());
	m_CreepSkullManager->Update(deltaTime);
	m_Boss->setTarget(m_Player->GetAnimation()->getPosition());
	m_Boss->Update(deltaTime);
}

void Level4::Draw(sf::RenderWindow* window)
{
	m_Boss->Draw(window);
	m_CreepSkullManager->Draw(window);
}

void Level4::Reset()
{
	m_CreepSkullManager->Reset();
}

bool Level4::isNeedNextLevel()
{
	return false;
}
