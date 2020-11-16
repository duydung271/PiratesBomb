#include "CreepManager.h"

CreepManager::CreepManager()
{
	m_Num = 10;
	m_currentTime = 0.f;
	m_BornTime = 0.1f;
	m_isAllowToBorn = true;
}

CreepManager::~CreepManager()
{
	for (auto it : m_ListCreep)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
	m_ListCreep.clear();
}


void CreepManager::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= m_BornTime)
	{
		if (m_isAllowToBorn) BornCreep();
		m_currentTime -= m_BornTime;
	}
	for (auto it : m_ListCreep)
	{
		it->setTarget(m_Target);
		it->Update(deltaTime);
	}
}

void CreepManager::Draw(sf::RenderWindow* window)
{
	for (auto it : m_ListCreep)
	{
		it->Draw(window);
	}
}

void CreepManager::setTarget(sf::Vector2f target)
{
	m_Target = target;
}

void CreepManager::Reset()
{
	for (auto it : m_ListCreep)
	{
		it->ResetAll();
	}
}

BaseCreep* CreepManager::getCreep()
{
	for (auto it : m_ListCreep)
	{
		if (!it->isActive())
		{
			return it;
		}
	}
	return nullptr;
}

bool CreepManager::BornCreep()
{
	BaseCreep* creep = getCreep();
	if (creep == nullptr) return false;
	creep->Awake();
	return true;
}

void CreepManager::setBornalbe(bool able)
{
	m_isAllowToBorn = able;
}

