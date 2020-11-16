#pragma once
#include "BaseCreep.h"
#include "BulletBossManager.h"
class Boss:public BaseCreep
{
public:
	Boss();
	~Boss();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void CountDead()
	{

	}
	void CountBorn()
	{

	}
private:
	void CreateBodyBoss();
	AnimationComponent* m_AniAttack;
	BulletBossManager* m_BulletManager;
	bool m_Intro;
	float m_CurrentTime;

};