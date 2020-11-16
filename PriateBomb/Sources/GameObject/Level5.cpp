#include "Level5.h"

Level5::Level5()
{
}

Level5::~Level5()
{
	
}

void Level5::Init(IPlayer* player)
{
	m_MonsterManager = new MonsterManager();
	m_MonsterManager->Init();
}

void Level5::Update(float deltaTime)
{
	
}

void Level5::Draw(sf::RenderWindow* window)
{
	
}

void Level5::Reset()
{
}

bool Level5::isNeedNextLevel()
{
	return false;
}
