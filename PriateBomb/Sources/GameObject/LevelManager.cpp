#include "LevelManager.h"
LevelManager::~LevelManager()
{
	for (auto it : m_Level)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
}
void LevelManager::Init(IPlayer* player)
{
	m_Level.resize(LEVEL_NULL);
	m_Level[LEVEL_1] = new Level1();
	m_Level[LEVEL_2] = new Level2();
	m_Level[LEVEL_3] = new Level3();
	m_Level[LEVEL_4] = new Level4();
	m_Level[LEVEL_5] = new Level5();
	for (auto it : m_Level)
	{
		it->Init(player);
	}
	m_nextLevel = LEVEL_NULL;
	m_LEVELth = LevelManager::LEVEL_1;
	m_currentLevel = m_Level[m_LEVELth];
	m_currentTime = 0.f;
	m_timeChange = 100.f;
	

}

void LevelManager::Update(float deltaTime)
{
	PerformLevel();
	if (m_currentLevel->isNeedNextLevel()) NextLevel();
	m_currentLevel->Update(deltaTime);
}

void LevelManager::Draw(sf::RenderWindow* window)
{
	m_currentLevel->Draw(window);
}

void LevelManager::ChangeNextLevel(LEVEL next)
{
	m_nextLevel = next;
}

void LevelManager::NextLevel()
{
	LEVEL next = static_cast<LEVEL>(m_LEVELth + 1);
	if (next < LEVEL_5)
	{
		ChangeNextLevel(next);
	}
}

void LevelManager::PerformLevel()
{
	if (m_nextLevel == LEVEL_NULL) return;
	m_currentLevel->Reset();
	m_LEVELth = m_nextLevel;
	m_nextLevel = LEVEL_NULL;
	m_currentLevel = m_Level[m_LEVELth];
}

LevelManager::LEVEL LevelManager::getLevel()
{
	return m_LEVELth;
}
