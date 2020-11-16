#include "BulletBossManager.h"

BulletBossManager::BulletBossManager()
{
	m_Num = 100;
	m_currentTime = 0.f;
	m_BornTime = 0.001f;
}

BulletBossManager::~BulletBossManager()
{
	
	
	for (auto it : m_listCreepBullet)
	{
		if (it != nullptr)
		{
			delete it;
		}
		it = nullptr;
	}
	m_listCreepBullet.clear();
}

void BulletBossManager::Init()
{
	
	for (int i = 0; i < m_Num; i++)
	{
		CreepBullet* creepBullet = new CreepBullet();
		creepBullet->Init();
		creepBullet->setActive(false);
		creepBullet->getBody()->SetActive(false);
		m_listCreepBullet.push_back(creepBullet);
	}
}

void BulletBossManager::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	m_startAniAttack = false;
	if (m_currentTime >= m_BornTime)
	{
		m_startAniAttack = true;
		m_currentTime -= m_BornTime;
	}
	if (m_CallBack == true)
	{
		BornCreepBullet();
		m_CallBack = false;
	}
	
	for (auto it : m_listCreepBullet)
	{
		it->setTarget(m_Target);
		it->Update(deltaTime);
	}
}

void BulletBossManager::Draw(sf::RenderWindow* window)
{
	
	for (auto it : m_listCreepBullet)
	{
		it->Draw(window);
	}

}

void BulletBossManager::setTarget(sf::Vector2f target)
{
	m_Target = target;
}



CreepBullet* BulletBossManager::getCreepBullet()
{
	for (auto it : m_listCreepBullet)
	{
		if (!it->isActive())
		{
			return it;
		}
	}
	return nullptr;
}

void BulletBossManager::setPositionAppear(sf::Vector2f pos)
{
	m_PositionAppear = pos;
}

void BulletBossManager::BornCreepBullet()
{
	CreepBullet* creepBullet = getCreepBullet();
	if (creepBullet == nullptr) return;
	creepBullet->Reset();
	creepBullet->setActive(true);
	creepBullet->getBody()->SetActive(true);
	creepBullet->getBody()->SetAwake(true);
	creepBullet->Call();
	creepBullet->getBody()->SetTransform(World::ConvertToPM(m_PositionAppear), 0);
}

void BulletBossManager::setCallBack(bool isCallBack)
{
	m_CallBack = isCallBack;
}

bool BulletBossManager::isCallBack()
{
	return m_CallBack;
}

bool BulletBossManager::isStartAniAttack()
{
	return m_startAniAttack;
}
