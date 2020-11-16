#pragma once
#include "IPlayer.h"
#include "CreepBatManager.h"
#include "CreepBeeManager.h"
#include "CreepBlueBirdManager.h"
#include "CreepSkullManager.h"
#include "CreepSunDragonManager.h"
#include "Boss.h"

class ILevel
{
public:
	virtual void Init(IPlayer* player)=0;
	virtual void Update(float deltaTime)=0;
	virtual void Draw(sf::RenderWindow* window)=0;
	virtual void Reset()=0;
	virtual bool isNeedNextLevel() = 0;
};