#include "CreepSkullManager.h"

CreepSkullManager::CreepSkullManager()
{
	m_Num = 150;
	m_BornTime = 0.01f;
}

CreepSkullManager::~CreepSkullManager()
{
}

void CreepSkullManager::Init()
{
	for (int i = 0; i < m_Num; i++)
	{
		CreepSkull* creep = new CreepSkull();
		creep->Init();
		creep->setActive(false);
		m_ListCreep.push_back(creep);
	}
}
