#include "DeadGroundState.h"

DeadGroundState::DeadGroundState(IPlayer* player)
{
	m_Player = player;
}

void DeadGroundState::Init()
{
}

void DeadGroundState::Draw(sf::RenderWindow* window)
{
}

void DeadGroundState::Update(float deltaTime)
{
	if (m_Player->GetAnimation()->isEndFrame())
	{
		m_Player->GetAnimation()->Stop();
	}
}
