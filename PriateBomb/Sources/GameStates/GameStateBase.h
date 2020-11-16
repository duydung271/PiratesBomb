#pragma once
#include "../GameManager/ResourceManager.h"
#include "GameStateMachine.h"
#include "../GameObject/AnimationComponent.h"
#include "../GameObject/LayerShadow.h"

extern StateTypes;
class GameStateBase
{
public:
	GameStateBase();
	virtual ~GameStateBase();

	virtual void Exit() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void Init() = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render() = 0;
	static void setWindow(sf::RenderWindow* target);

	static GameStateBase* CreateState(StateTypes stt);

	static sf::RenderWindow* Window;
};


