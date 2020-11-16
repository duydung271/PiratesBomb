#include "JumpAnticipation.h"

JumpAnticipationPState::JumpAnticipationPState(IPlayer* player)
{
	m_Player = player;
}

void JumpAnticipationPState::Init()
{
}

void JumpAnticipationPState::Draw(sf::RenderWindow* window)
{
}

void JumpAnticipationPState::Update(float deltaTime)
{
	if (m_Player->GetAnimation()->isEndFrame())
	{
		m_Player->GetAnimation()->Reset();
		m_Player->SetNextAction(IPState::Jump);	
	}
	if (m_Player->GetAttribute()->isHit()) m_Player->SetNextAction(IPState::Hit);
	if (m_Player->GetAttribute()->isDead()) m_Player->SetNextAction(IPState::DeadHit);
}
