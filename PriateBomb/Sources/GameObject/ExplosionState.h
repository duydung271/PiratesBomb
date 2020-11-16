#pragma once
#include "IBombState.h"

class ExpolsionState
	:public IBombState
{
public:
	ExpolsionState(IBomb* bomb)
	{
		m_Bomb = bomb;
		m_CurrentTime = 0.f;
	}
	~ExpolsionState();
	void Init();
	void Update(const float deltaTime);
	void Draw(sf::RenderWindow* window);
private:
	IBomb* m_Bomb;
	float m_CurrentTime;
	ExplosionEffect* m_ExplosionEffect;
};