#include "GameStateBase.h"
#include "GSIntro.h"
#include "GSGameplay.h"
#include "GSMenu.h"

sf::RenderWindow* GameStateBase::Window = nullptr;

GameStateBase::GameStateBase()
{
}

GameStateBase::~GameStateBase()
{
}

void GameStateBase::setWindow(sf::RenderWindow* target)
{
	Window = target;
}

GameStateBase* GameStateBase::CreateState(StateTypes stt)
{
	GameStateBase* gs=nullptr;
	switch (stt)
	{
	case STATE_INVALID:
		break;
	case STATE_Intro:
		gs = new GSIntro();
		break;
	case STATE_Menu:
		gs = new GSMenu();
		break;
	case STATE_Play:
		gs = new GSGameplay();
		break;
	default:
		break;
	}
	return gs;
}
