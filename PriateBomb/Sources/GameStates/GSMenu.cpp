#include "GSMenu.h"

GSMenu::GSMenu()
{
	m_currentTime = 0.0f;
}

GSMenu::~GSMenu()
{
	if (m_BackGround != nullptr)
	{
		delete m_BackGround;
	}
	m_BackGround = nullptr;
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	m_BackGround = new sf::Sprite();
	m_BackGround->setTexture(*ResourceManagers::GetInstance()->GetTexture("logo"));
}

void GSMenu::Update(const float& dt)
{
}

void GSMenu::Render()
{
	Window->draw(*m_BackGround);
}
