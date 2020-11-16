#pragma once
#include "IPState.h"
#include "HitBoxComponent.h"
#include "AnimationComponent.h"
#include "AttributeComponent.h"

#include "BombManager.h"

class IPlayer
{
public:
    virtual void SetAction() = 0;
    virtual void SetState(IPState* StatePtr) = 0;

    virtual IPState* GetState() = 0;
    virtual b2Body* GetBody() = 0;
    virtual AnimationComponent* GetAnimation() = 0;
    virtual AttributeComponent* GetAttribute() = 0;

    virtual void SetNextAction(IPState::STATE) = 0;
   
};