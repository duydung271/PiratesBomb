#include "CreepBlueBirdManager.h"

CreepBlueBirdManager::CreepBlueBirdManager()
{
}

CreepBlueBirdManager::~CreepBlueBirdManager()
{
}

void CreepBlueBirdManager::Init()
{
	for (int i = 0; i < m_Num; i++)
	{
		CreepBlueBird* creep = new CreepBlueBird();
		creep->Init();
		creep->setActive(false);
		m_ListCreep.push_back(creep);
	}
}
