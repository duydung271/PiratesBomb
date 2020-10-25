#pragma once
#include "../GameObject/AnimationComponent.h"
#include "../GameObject/MovementComponent.h"

class PlayerBombGuy
	:sf::Drawable
{
public:
	PlayerBombGuy();
	~PlayerBombGuy();

	void Init();
	void Update(const float& deltaTime);

protected:
	AnimationComponent* m_AnimationComponent;
	MovementComponent* m_MovementComponent;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= m_MovementComponent->getTransform();
		target.draw(*m_AnimationComponent, states);
	}
private:
	enum PlayerBombGuyState
	{
		Idle = 0,
		Run,
		JumpAnticipation,
		Jump,
		Fall,
		Hit,
		DeadHit,
		DeadGround,
		DoorIn,
		DoorOut,
	};

};