#include "GSIntro.h"

GSIntro::GSIntro()
{
	
}

GSIntro::~GSIntro()
{
	
}

void GSIntro::Exit()
{
	
}

void GSIntro::Pause()
{
	m_CurrentTime = 0.f;
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
	m_CurrentTime = 0.f;
	GameButton::setWindow(Window);
	m_Button_Play = new GameButton("Barrel");
	m_Button_Play->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		});
}

void GSIntro::Update(const float& dt)
{
	m_Button_Play->Update(dt);
}

void GSIntro::Render()
{
	Window->draw(*m_Button_Play);		
}
