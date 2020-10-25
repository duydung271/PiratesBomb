#pragma once
#include "GameStateBase.h"
#include "../GameObject/GameButton.h"

class GSIntro
	:public GameStateBase
{
public:
	GSIntro();
	virtual ~GSIntro();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(const float& dt);
	void Render();
private:
	float m_CurrentTime;
	GameButton* m_Button_Play;
};
