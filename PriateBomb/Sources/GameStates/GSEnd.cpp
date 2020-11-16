#include "GSEnd.h"
#include "../GameObject/ItemManager.h"
#include "../GameObject/DataGamePlay.h"
StateTypes GSEnd::m_nextState = STATE_INVALID;
GSEnd::GSEnd()
{
	
}

GSEnd::~GSEnd()
{
	
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	BackGround::GetInstance()->setAllowDrawTree(false);
	auto button = new GameButton("Button//menu");
	button->SetOnClick([]() {
		m_nextState = STATE_Menu;
		
		});
	button->setPosition(screenWidth/2-100, screenHeight/2+300);
	button->setScale(0.5f, 0.5f);
	m_ListButton.push_back(button);

	button = new GameButton("Button//restart");
	button->SetOnClick([]() {
		m_nextState = STATE_Play;
		});
	button->setPosition(screenWidth / 2 + 100, screenHeight / 2 + 300);
	button->setScale(0.5f, 0.5f);
	m_ListButton.push_back(button);
	
	m_LayerLight.setFillColor(sf::Color::Black);
	m_LayerLight.setDir(false);
	m_LayerOut.setFillColor(sf::Color::Black);
	m_LayerOut.setDir(true);

	m_Text.setString("GAME OVER");
	m_Text.setFont(*ResourceManagers::GetInstance()->GetFont("Planes_ValMore"));
	m_Text.setPosition(screenWidth / 2-600.f, screenHeight / 2-200);
	m_Text.setFillColor(sf::Color::Red);
	m_Text.setCharacterSize(200);
	m_Text.setOutlineColor(sf::Color::Black);
	m_Text.setOutlineThickness(1.f);
}

void GSEnd::Update(const float& dt)
{
	BackGround::GetInstance()->Update(dt);
	if (m_nextState != STATE_INVALID)
	{
		m_LayerOut.Update(dt);
		if (m_LayerOut.isEnd())
		{
			if (m_nextState == STATE_Play)
			{
				GameStateMachine::GetInstance()->PopState();
				GameStateMachine::GetInstance()->PopState();
				GameStateMachine::GetInstance()->ChangeState(m_nextState);
				//GameStateMachine::GetInstance()->NextState()->Init();
			}
			else if (m_nextState == STATE_Menu)
			{
				GameStateMachine::GetInstance()->PopState();
				GameStateMachine::GetInstance()->PopState();
			}
			ItemManager::GetInstance()->Reset();
			DataGamePlay::GetInstance()->Reset();

			m_nextState = STATE_INVALID;
			m_LayerLight.setFillColor(sf::Color::Black);
			m_LayerLight.setDir(false);
			m_LayerOut.setFillColor(sf::Color::Black);
			m_LayerOut.setDir(true);
		}
	}
	m_LayerLight.Update(dt);
	for (auto it : m_ListButton)
	{
		it->Update(dt);
	}
}

void GSEnd::Render()
{
	BackGround::GetInstance()->Draw(Window);
	
	for (auto it : m_ListButton)
	{
		Window->draw(*it);
	}
	Window->draw(m_Text);
	Window->draw(m_LayerLight);
	Window->draw(m_LayerOut);
}
