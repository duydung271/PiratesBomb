#include "GameButton.h"

sf::RenderWindow* GameButton::m_Window = nullptr;

GameButton::GameButton(std::string nameSprite)
{
	m_Sprite = new sf::Sprite();
	m_Sprite->setTexture(*ResourceManagers::GetInstance()->GetTexture(nameSprite));
	m_pBtClick = nullptr;
	m_isHandle = false;
	m_CurrentTime = 0.f;
	m_TimeRelease = 0.5f;
	
}

GameButton::~GameButton()
{
	if (m_Sprite != nullptr)
	{
		delete m_Sprite;
		m_Sprite = nullptr;
	}
}

void GameButton::SetOnClick(void(*pBtClickFun)())
{
	m_pBtClick = pBtClickFun;
}

void GameButton::HandleTouchEvents()
{
	m_isHandle = false;
	sf::FloatRect rectMouse(sf::Mouse::getPosition(*m_Window).x, sf::Mouse::getPosition(*m_Window).y, 0.00001f, 0.00001f);
	if (m_Sprite->getLocalBounds().intersects(rectMouse))
	{
		m_pBtClick();
		m_isHandle = true;
	} 
}

bool GameButton::IsHandle()
{
	return m_isHandle;
}

void GameButton::Update(const float& deltaTime)
{
	m_CurrentTime += deltaTime;
	if (m_CurrentTime>m_TimeRelease)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			HandleTouchEvents();
			if (IsHandle()) m_CurrentTime -= m_TimeRelease;
		}
		if (m_CurrentTime > 2.f * m_TimeRelease)
		{
			m_CurrentTime-= m_TimeRelease;
		}
	}
}

void GameButton::setWindow(sf::RenderWindow* window)
{
	m_Window = window;
}

