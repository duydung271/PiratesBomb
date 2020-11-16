#include "HitState.h"

HitState::HitState(IPlayer* player)
{
	m_Player = player;
}

void HitState::Init()
{
}

void HitState::Draw(sf::RenderWindow* window)
{
}

void HitState::Update(float deltaTime)
{

	if (m_Player->GetAnimation()->isEndFrame())
	{
		m_Player->GetAnimation()->Stop();
		m_Player->SetNextAction(IPState::Idle);
	}
}
