#pragma once
#include "IBulletState.h"

class FireState
	:public IBulletState
{
public:
	FireState(IBullet* bullet);
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void setTransform(sf::Vector2f pos, float angle);
private:
	IBullet* m_Bullet;
	AnimationComponent* m_Ani;
	float m_currentTime;
};