#include "MonsterManager.h"

MonsterManager::MonsterManager()
{
	m_Num = 10;
	m_currentTime = 0.f;
	m_BornTime = 2.f;
}

MonsterManager::~MonsterManager()
{
	for (auto it : m_ListBat)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
	m_ListBat.clear();

	for (auto it : m_ListBee)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
	m_ListBee.clear();

	for (auto it : m_ListBlueBird)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
	m_ListBlueBird.clear();

	for (auto it : m_ListSkull)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
	m_ListSkull.clear();
	for (auto it : m_ListSunDragon)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
	m_ListSunDragon.clear();
}

void MonsterManager::Init()
{
	for (int i = 0; i < m_Num; i++)
	{
		CreepBat* bat = new CreepBat();
		bat->Init();
		bat->setActive(false);
		m_ListBat.push_back(bat);
	}

	for (int i = 0; i < m_Num; i++)
	{
		CreepBee* bee = new CreepBee();
		bee->Init();
		bee->setActive(false);
		m_ListBee.push_back(bee);
	}

	for (int i = 0; i < m_Num; i++)
	{
		CreepBlueBird* blueBird = new CreepBlueBird();
		blueBird->Init();
		blueBird->setActive(false);
		m_ListBlueBird.push_back(blueBird);

	}
	for (int i = 0; i < m_Num; i++)
	{
		CreepSkull* Skull = new CreepSkull();
		Skull->Init();
		Skull->setActive(false);
		m_ListSkull.push_back(Skull);
	}
	for (int i = 0; i < m_Num; i++)
	{
		CreepSunDragon* SunDragon = new CreepSunDragon();
		SunDragon->Init();
		SunDragon->setActive(false);
		m_ListSunDragon.push_back(SunDragon);
	}
}

void MonsterManager::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= m_BornTime)
	{
		BornCreepBat();
		BornCreepBee();
		BornCreepBlueBird();
		BornCreepSunDragon();
		BornCreepSkull();

		m_currentTime -= m_BornTime;
	}
	for (auto it : m_ListBat)
	{
		it->setTarget(m_Target);
		it->Update(deltaTime);
	}
	for (auto it : m_ListBlueBird)
	{
		it->setTarget(m_Target);
		it->Update(deltaTime);
	}
	for (auto it : m_ListBee)
	{
		it->setTarget(m_Target);
		it->Update(deltaTime);
	}
	for (auto it : m_ListSkull)
	{
		it->setTarget(m_Target);
		it->Update(deltaTime);
	}
	for (auto it : m_ListSunDragon)
	{
		it->setTarget(m_Target);
		it->Update(deltaTime);
	}

}

void MonsterManager::Draw(sf::RenderWindow* window)
{
	for (auto it : m_ListSunDragon)
	{
		it->Draw(window);
	}
	for (auto it : m_ListBat)
	{
		it->Draw(window);
	}
	for (auto it : m_ListBee)
	{
		it->Draw(window);
	}
	for (auto it : m_ListBlueBird)
	{
		it->Draw(window);
	}
	for (auto it : m_ListSkull)
	{
		it->Draw(window);
	}
	
	
}

void MonsterManager::setTarget(sf::Vector2f target)
{
	m_Target = target;
}

CreepBat* MonsterManager::getCreepBat()
{
	for (auto it : m_ListBat)
	{
		if (!it->isActive())
		{
			return it;
		}
	}
	return nullptr;
}

CreepBee* MonsterManager::getCreepBee()
{
	for (auto it : m_ListBee)
	{
		if (!it->isActive())
		{
			return it;
		}
	}
	return nullptr;
}

CreepBlueBird* MonsterManager::getCreepBlueBird()
{
	for (auto it : m_ListBlueBird)
	{
		if (!it->isActive())
		{
			return it;
		}
	}
	return nullptr;
}

CreepSkull* MonsterManager::getCreepSkull()
{
	for (auto it : m_ListSkull)
	{
		if (!it->isActive())
		{
			return it;
		}
	}
	return nullptr;
}

CreepSunDragon* MonsterManager::getCreepSunDragon()
{
	for (auto it : m_ListSunDragon)
	{
		if (!it->isActive())
		{
			return it;
		}
	}
	return nullptr;
}

void MonsterManager::BornCreepBat()
{
	CreepBat* bat = getCreepBat();
	if (bat == nullptr) return;
	bat->Awake();
}

void MonsterManager::BornCreepBee()
{
	CreepBee* bee = getCreepBee();
	if (bee == nullptr) return;
	bee->Awake();
}

void MonsterManager::BornCreepBlueBird()
{
	CreepBlueBird* blueBird = getCreepBlueBird();
	if (blueBird == nullptr) return;
	blueBird->Awake();
}

void MonsterManager::BornCreepSkull()
{
	CreepSkull* Skull = getCreepSkull();
	if (Skull == nullptr) return;
	Skull->Awake();
}

void MonsterManager::BornCreepSunDragon()
{
	CreepSunDragon* SunDragon = getCreepSunDragon();
	if (SunDragon == nullptr) return;
	SunDragon->Awake();
}
