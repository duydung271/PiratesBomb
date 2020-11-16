#pragma once
#include "BaseCreep.h"

class CreepBat:public BaseCreep
{
public:
	CreepBat();
	~CreepBat();
	void Init();
	void Update(float deltaTime);
	void CountDead()
	{
		DataGamePlay::GetInstance()->CountBatDead();
		
	}
	void CountBorn()
	{
		DataGamePlay::GetInstance()->CountBatBorn();
	}
private:

};