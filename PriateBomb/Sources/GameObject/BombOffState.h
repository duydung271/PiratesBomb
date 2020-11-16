#pragma once
#include "IBombState.h"

class BombOffState
	:public IBombState
{
public:
	BombOffState(IBomb* bomb)
	{
		m_Bomb = bomb;
		m_CurrentTime = 0.f;
	}
	void Init();
	void Update(const float deltaTime);
	void Draw(sf::RenderWindow* window);
private:
	IBomb* m_Bomb;
	float m_CurrentTime;
};