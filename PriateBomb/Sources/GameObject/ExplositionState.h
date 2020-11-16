#pragma once
#include "IBulletState.h"
#include "ExplosionEffect.h"

class ExplositionState
	:public IBulletState
{
public:
	ExplositionState(IBullet* bullet);
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void setTransform(sf::Vector2f pos, float angle);
private:
	IBullet* m_Bullet;
	AnimationComponent* m_Ani;
	float m_CurrentTime;
	b2Vec2 m_SavePoint;
	ExplosionEffect* m_ExplosionEffect;
};