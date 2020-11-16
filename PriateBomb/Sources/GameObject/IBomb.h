#pragma once
#include "ExplosionEffect.h"

class IBombState;

class IBomb
{
public:
	static enum STATE
	{
		STATE_BOMBOFF = 0,
		STATE_BOMBON,
		STATE_EXPLOSION,
		STATE_STOP,
		STATE_NULL,
	};
	virtual void setNextState(STATE newState)=0;

    virtual void SetAction() = 0;
    virtual void SetState(IBombState* StatePtr) = 0;

    virtual b2Body* GetBody() = 0;
    virtual AnimationComponent* GetAnimation() = 0;
	virtual float getCoolDownTime()=0;
};