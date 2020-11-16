#include "ExplositionState.h"

ExplositionState::ExplositionState(IBullet* bullet)
{
	m_Bullet = bullet;
	
}

void ExplositionState::Init()
{
	m_Ani = new AnimationComponent();
	m_Ani->Init("BulletExplosion");
	m_CurrentTime = 0.f;
	m_Ani->setScale(2,2);

	m_ExplosionEffect = new ExplosionEffect(m_Bullet->getBody());
	m_ExplosionEffect->setBlastPower(100);
}

void ExplositionState::Update(float deltaTime)
{
	if (m_CurrentTime == 0.f)
	{
		m_ExplosionEffect->explode_proximity();
		m_SavePoint = m_Bullet->getBody()->GetPosition();
		m_Bullet->getBody()->SetActive(false);
		m_Bullet->getBody()->SetSleepingAllowed(false);
	}
	m_CurrentTime += deltaTime;
	m_Bullet->getBody()->SetTransform(m_SavePoint,0.f);
	if (m_Ani->isEndFrame())
	{
		m_Bullet->getEntity()->setActive(false);
		m_Ani->Reset();
		m_CurrentTime = 0.f;
	}
	m_Ani->Update(deltaTime);
}

void ExplositionState::Draw(sf::RenderWindow* window)
{
	window->draw(*m_Ani);
}

void ExplositionState::setTransform(sf::Vector2f pos, float angle)
{
	m_Ani->setPosition(pos);
	m_Ani->setRotation(angle);
}
