#include "CreepBatManager.h"

CreepBatManager::CreepBatManager()
{
}

CreepBatManager::~CreepBatManager()
{
}

void CreepBatManager::Init()
{
	for (int i = 0; i < m_Num; i++)
	{
		CreepBat* creep = new CreepBat();
		creep->Init();
		creep->setActive(false);
		m_ListCreep.push_back(creep);
	}
}
