#include "BombOnState.h"

void BombOnState::Init()
{
	m_CurrentTime = 0.f;
}

void BombOnState::Update(const float deltaTime)
{
	m_CurrentTime += deltaTime;
	
	if (m_CurrentTime >= m_Bomb->getCoolDownTime())
	{
		m_Bomb->setNextState(IBomb::STATE_EXPLOSION);
		m_CurrentTime = 0.f;
	}
}

void BombOnState::Draw(sf::RenderWindow* window)
{
}
