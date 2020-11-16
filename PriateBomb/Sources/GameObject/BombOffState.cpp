#include "BombOffState.h"

void BombOffState::Init()
{
}

void BombOffState::Update(const float deltaTime)
{
	if (m_CurrentTime == 0.f)
	{
		m_Bomb->GetBody()->SetActive(true);
		m_Bomb->GetBody()->SetAwake(true);
	}
	m_CurrentTime += deltaTime;
	if (m_CurrentTime >= 0.05f)
	{
		m_Bomb->setNextState(IBomb::STATE_BOMBON);
		m_CurrentTime = 0.f;
	}
}
void BombOffState::Draw(sf::RenderWindow* window)
{
}
