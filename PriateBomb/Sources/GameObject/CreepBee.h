#pragma once
#include "BaseCreep.h"

class CreepBee :public BaseCreep
{
public:
	CreepBee();
	~CreepBee();
	void Init();
	void Update(float deltaTime);
	void CountDead()
	{
		DataGamePlay::GetInstance()->CountBeeDead();
	}
	void CountBorn()
	{
		DataGamePlay::GetInstance()->CountBeeBorn();
	}
private:

};