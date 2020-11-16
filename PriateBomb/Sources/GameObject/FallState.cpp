#include "FallState.h"

FallPState::FallPState(IPlayer* player)
{
	m_Player = player;
}

void FallPState::Init()
{
}

void FallPState::Draw(sf::RenderWindow* window)
{
}

void FallPState::Update(float deltaTime)
{
	sf::Vector2f velocity(m_Player->GetBody()->GetLinearVelocity().x, m_Player->GetBody()->GetLinearVelocity().y);
	velocity = velocity * SCALE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = m_Player->GetAttribute()->getVelocity().x;
		m_Player->GetAnimation()->setDirect(DIRECT::DIRECT_RIGHT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = -m_Player->GetAttribute()->getVelocity().x;
		m_Player->GetAnimation()->setDirect(DIRECT::DIRECT_LEFT);
	}

	m_Player->GetBody()->SetLinearVelocity(World::ConvertToPM(velocity));

	if (m_Player->GetAnimation()->isEndFrame())
	{
		m_Player->GetAnimation()->Stop();
	}
	if (m_Player->GetBody()->GetLinearVelocity().y ==0.f)
	{
		m_Player->SetNextAction(IPState::Ground);
		m_Player->GetAnimation()->Reset();
	}
	if (m_Player->GetAttribute()->isHit()) m_Player->SetNextAction(IPState::Hit);
	if (m_Player->GetAttribute()->isDead()) m_Player->SetNextAction(IPState::DeadHit);
}
