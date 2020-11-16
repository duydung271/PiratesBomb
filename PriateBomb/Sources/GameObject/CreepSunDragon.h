#pragma once
#include "BaseCreep.h"

class CreepSunDragon :public BaseCreep
{
public:
	CreepSunDragon();
	~CreepSunDragon();
	void Init();
	void Update(float deltaTime);
	void CountDead()
	{
		DataGamePlay::GetInstance()->CountSunDragonDead();
	}
	void CountBorn()
	{
		DataGamePlay::GetInstance()->CountSunDragonBorn();
	}
private:
	sf::Vector2f m_AniPosOffSet;
};