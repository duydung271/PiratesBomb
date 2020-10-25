#include "GSGameplay.h"

GSGameplay::GSGameplay()
{
	
}

GSGameplay::~GSGameplay()
{
	
}

void GSGameplay::Exit()
{
}

void GSGameplay::Pause()
{
}

void GSGameplay::Resume()
{
}

void GSGameplay::Init()
{
	m_TileMap = new TileMap();
	m_TileMap->Load("Map0.json");
	m_Button_Exit = new GameButton("Windows");
	m_Button_Exit->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
}

void GSGameplay::Update(const float& dt)
{
	m_Button_Exit->Update(dt);
}

void GSGameplay::Render()
{
	Window->draw(*m_TileMap);
	Window->draw(*m_Button_Exit);
}
