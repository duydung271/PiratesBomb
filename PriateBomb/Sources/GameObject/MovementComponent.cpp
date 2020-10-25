#include "MovementComponent.h"

MovementComponent::MovementComponent()
{
	m_Velocity = sf::Vector2f(0.f, 0.f);
	m_deltaTime = 0.f;
	m_Active = MOVE_STAND;
}

void MovementComponent::MoveUp()
{
	move(sf::Vector2f(0.f, -m_Velocity.y));
}

void MovementComponent::MoveDown()
{
	move(sf::Vector2f(0.f, m_Velocity.y));
}

void MovementComponent::MoveLeft()
{
	move(sf::Vector2f(-m_Velocity.x,0.f ));
}

void MovementComponent::MoveRight()
{
	move(sf::Vector2f(m_Velocity.x, 0.f));
}

void MovementComponent::Stand()
{
	move(sf::Vector2f(10.f, 0.f));
}

void MovementComponent::Update(const float& deltaTime)
{
	m_deltaTime = deltaTime;
	switch (m_Active)
	{
	case MOVE_STAND:
		void Stand();
	case MOVE_LEFT:
		void MoveLeft();
	case MOVE_RIGHT:
		void MoveRight();
	case MOVE_UP:
		void MoveUp();
	case MOVE_DOWN:
		void MoveDown();
	default:
		break;
	}
}

void MovementComponent::SetMoveActive(MOVE newState)
{
	m_Active = newState;
}
