#include "IdlePState.h"

IdlePState::IdlePState(IPlayer* player)
{
	m_Player = player;
}

void IdlePState::Init()
{
	m_CurrentTime = 0.f;
}

void IdlePState::Draw(sf::RenderWindow* window)
{
}

void IdlePState::Update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Player->SetNextAction(IPState::Run);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_Player->GetBody()->GetLinearVelocity().y <= 0.f)
	{
		m_Player->SetNextAction(IPState::JumpAnticipation);
	}
	if (m_Player->GetAttribute()->isHit()) m_Player->SetNextAction(IPState::Hit);
	if (m_Player->GetAttribute()->isDead()) m_Player->SetNextAction(IPState::DeadHit);
}
