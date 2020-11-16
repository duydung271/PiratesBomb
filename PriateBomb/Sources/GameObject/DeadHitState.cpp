#include "DeadHitState.h"

DeadHitState::DeadHitState(IPlayer* player)
{
	m_Player = player;
}

void DeadHitState::Init()
{
}

void DeadHitState::Draw(sf::RenderWindow* window)
{
}

void DeadHitState::Update(float deltaTime)
{
	if (m_Player->GetAnimation()->isEndFrame())
	{
		m_Player->SetNextAction(IPState::DeadGroundState);
	}
}
