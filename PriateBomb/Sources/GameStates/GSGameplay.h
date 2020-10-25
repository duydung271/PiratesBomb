#pragma once
#include "GameStateBase.h"
#include "../GameObject/TileMap.h"
#include "../GameObject/GameButton.h"

class GSGameplay
	:public GameStateBase
{
public:
	GSGameplay();
	virtual ~GSGameplay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(const float& dt);
	void Render();
private:
	TileMap* m_TileMap;
	float m_currentTime;
	GameButton* m_Button_Exit;
};
