#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitCircleComponent.h"


enum ParticlesSTATE
{
	STATE_JUMP=0,
	STATE_RUN,
	STATE_FALL,
};

class IPState
{
public:
	enum STATE
	{
		Idle = 0,
		Run,
		JumpAnticipation,
		Jump,
		Fall,
		Ground,
		Hit,
		DeadHit,
		DeadGroundState,
		DoorIn,
		DoorOut,
		STATE_NULL,
	};
	virtual void Init() = 0;
	virtual void Update(const float deltaTime) = 0;
	virtual void Draw(sf::RenderWindow* window) = 0;
};