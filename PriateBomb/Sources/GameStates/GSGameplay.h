#pragma once
#include "GameStateBase.h"
#include "../GameObject/TileMap.h"
#include "../GameObject/GameButton.h"
#include "../GameObject/Player.h"
#include "../GameObject/HitCircleComponent.h"
#include "../GameObject/Bomb.h"
#include "../GameObject/ExplosionEffect.h"
#include "../GameObject/BackGround.h"
#include "../GameObject/Boss.h"
#include "../GameObject/ItemManager.h"
#include "../GameObject/LevelManager.h"

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
	float m_currentTime;
	TileMap* m_TileMap;
	b2World* m_World;
	Player* m_Player;
	LevelManager* m_LevelManger;
	LayerShadow m_LayerIntro;
	LayerShadow m_LayerLight;
	LayerShadow m_LayerTop;
	bool m_wasInit;

	bool m_ModeTool;
};
