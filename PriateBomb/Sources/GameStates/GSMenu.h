#pragma once
#include "GameStateBase.h"

class GSMenu
	:public GameStateBase
{
public:
	GSMenu();
	virtual ~GSMenu();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(const float& dt);
	void Render();
private:
	sf::Sprite* m_BackGround;
	float m_currentTime;
};
