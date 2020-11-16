#pragma once
#include "BaseCreep.h"

class CreepBullet :public BaseCreep
{
public:
	CreepBullet();
	~CreepBullet();
	void Init();
	void Update(float deltaTime);
	void Call();
	bool isCollisionWithGround();
	void CountDead()
	{

	}
	void CountBorn()
	{

	}
private:
	bool m_isCalled;
	void createBody();
};