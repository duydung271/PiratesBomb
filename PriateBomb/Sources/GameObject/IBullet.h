#pragma once
#include "../GameManager/ResourceManager.h"
class IBulletState;
class IBullet
{
public:
	enum STATE_BULLET
	{
		STATE_FIRE = 0,
		STATE_EXPLORSION,
		STATE_NULL,
	};
	virtual void setNextState(STATE_BULLET newState)=0;
	virtual b2Body* getBody() = 0;
	virtual bool isCollision()=0;
	virtual Entity* getEntity()=0;
};