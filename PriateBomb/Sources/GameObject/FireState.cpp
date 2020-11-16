#include "FireState.h"

FireState::FireState(IBullet* bullet)
{
	m_Bullet = bullet;
}

void FireState::Init()
{
	m_Ani = new AnimationComponent();
	m_Ani->Init("BulletFire");
	m_currentTime = 0.f;
	
}

void FireState::Update(float deltaTime)
{
	if (m_currentTime == 0.f)
	{
		m_Bullet->getBody()->SetActive(true);
		m_Bullet->getBody()->SetSleepingAllowed(true);
		m_Bullet->getEntity()->setActive(true);
	}
	m_currentTime += deltaTime;
	if (m_Bullet->isCollision())
	{	
		m_Bullet->setNextState(IBullet::STATE_EXPLORSION);
		m_Ani->Reset();
		m_currentTime = 0.f;
		
	}
	m_Ani->Update(deltaTime);
}

void FireState::Draw(sf::RenderWindow* window)
{
	window->draw(*m_Ani);
}

void FireState::setTransform(sf::Vector2f pos, float angle)
{
	this->m_Ani->setPosition(pos);
	this->m_Ani->setRotation(angle);
}
