#pragma once
#include "CreepBat.h"
#include "CreepBee.h"
#include "CreepBlueBird.h"
#include "CreepSkull.h"
#include "CreepSunDragon.h"
#include "CreepBullet.h"

#include <list>

class MonsterManager
{
public:
	MonsterManager();
	~MonsterManager();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void setTarget(sf::Vector2f target);

	CreepBat* getCreepBat();
	CreepBee* getCreepBee();
	CreepBlueBird* getCreepBlueBird();
	CreepSkull* getCreepSkull();
	CreepSunDragon* getCreepSunDragon();
	



	void BornCreepBat();
	void BornCreepBee();
	void BornCreepBlueBird();
	void BornCreepSkull();
	void BornCreepSunDragon();


private:
	std::list<CreepBat*> m_ListBat;
	std::list<CreepBee*> m_ListBee;
	std::list<CreepBlueBird*> m_ListBlueBird;
	std::list<CreepSkull*> m_ListSkull;
	std::list<CreepSunDragon*> m_ListSunDragon;


	sf::Vector2f m_Target;
	int m_Num;
	float m_currentTime;
	float m_BornTime;


};