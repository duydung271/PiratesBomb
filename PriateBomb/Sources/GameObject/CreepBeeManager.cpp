#include "CreepBeeManager.h"

CreepBeeManager::CreepBeeManager()
{
}

CreepBeeManager::~CreepBeeManager()
{
}

void CreepBeeManager::Init()
{
	for (int i = 0; i < m_Num; i++)
	{
		CreepBee* creep = new CreepBee();
		creep->Init();
		creep->setActive(false);
		m_ListCreep.push_back(creep);
	}
}
