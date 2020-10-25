#pragma once
#include "../GameManager/ResourceManager.h"
class MovementComponent
	: public sf::Transformable
{
public:
	MovementComponent();
	enum MOVE
	{
		MOVE_STAND = 0,
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_NUMB,
	};
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Stand();
	void Update(const float& deltaTime);
	void SetMoveActive(MOVE newState);
protected:
	sf::Vector2f m_Velocity;
	float m_deltaTime;
	MOVE m_Active;	
};