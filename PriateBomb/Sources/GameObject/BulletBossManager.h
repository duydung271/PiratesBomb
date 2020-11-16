#pragma once
#include "CreepBat.h"
#include "CreepBee.h"
#include "CreepBlueBird.h"
#include "CreepSkull.h"
#include "CreepSunDragon.h"
#include "CreepBullet.h"

#include <list>

class BulletBossManager
{
public:
	BulletBossManager();
	~BulletBossManager();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void setTarget(sf::Vector2f target);

	CreepBullet* getCreepBullet();
	void setPositionAppear(sf::Vector2f pos);



	void BornCreepBullet();
	void setCallBack(bool isCallBack);
	bool isCallBack();
	bool isStartAniAttack();

private:
	
	std::list<CreepBullet*> m_listCreepBullet;

	sf::Vector2f m_Target;
	sf::Vector2f m_PositionAppear;
	int m_Num;
	float m_currentTime;
	float m_BornTime;

	bool m_CallBack;// goi quai ra
	bool m_startAniAttack;


};