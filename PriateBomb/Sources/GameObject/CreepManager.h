#pragma once
#include "BaseCreep.h"
#include "CreepBee.h"
#include "CreepBlueBird.h"
#include "CreepSkull.h"
#include "CreepSunDragon.h"
#include "CreepBullet.h"
#include "CreepBat.h"

#include <list>

class CreepManager
{
public:
	CreepManager();
	virtual ~CreepManager();
	virtual void Init()=0;
	virtual void Update(float deltaTime);
	virtual void Draw(sf::RenderWindow* window);
	virtual void setTarget(sf::Vector2f target);
	virtual void Reset();

	virtual BaseCreep* getCreep();
	virtual bool BornCreep();
	virtual void setBornalbe(bool able);


protected:
	std::list<BaseCreep*> m_ListCreep;
	sf::Vector2f m_Target;
	int m_Num;
	float m_currentTime;
	float m_BornTime;
	bool m_isAllowToBorn;
};