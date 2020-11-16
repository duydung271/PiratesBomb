#include "CreepSunDragonManager.h"

CreepSunDragonManager::CreepSunDragonManager()
{
	m_Num = 5;
}

CreepSunDragonManager::~CreepSunDragonManager()
{
}

void CreepSunDragonManager::Init()
{
	for (int i = 0; i < m_Num; i++)
	{
		CreepSunDragon* creep = new CreepSunDragon();
		creep->Init();
		creep->setActive(false);
		m_ListCreep.push_back(creep);
	}
}
