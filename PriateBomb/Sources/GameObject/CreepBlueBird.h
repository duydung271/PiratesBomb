#pragma once
#include "BaseCreep.h"

class CreepBlueBird :public BaseCreep
{
public:
	CreepBlueBird();
	~CreepBlueBird();
	void Init();
	void Update(float deltaTime);
	void CountDead()
	{
		DataGamePlay::GetInstance()->CountBlueBirdDead();
	}
	void CountBorn()
	{
		DataGamePlay::GetInstance()->CountBlueBirdBorn();
	}
private:

};