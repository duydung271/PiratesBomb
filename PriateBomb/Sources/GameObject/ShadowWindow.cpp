#include "ShadowWindow.h"

void ShadowWindow::Init()
{
	m_LayerColor.setSize(sf::Vector2f(screenWidth, screenHeight+100));
	m_LayerColor.setOrigin(m_LayerColor.getSize()*0.5f);
	m_LayerColor.setPosition(sf::Vector2f(screenWidth, screenHeight+100)*0.5f);
	m_ColorAlpha = 255;
	m_isUp = true;
	m_TimeSleep = 0.01f;
	m_Color = sf::Color(0, 0, 0);
}

void ShadowWindow::Update(float deltaTime)
{
	m_CurrentTime += deltaTime;
	
	if (m_CurrentTime > m_TimeSleep)
	{
		m_isEndProccess = false;
		if (m_isUp == true)
		{
			m_ColorAlpha--;
			if (m_ColorAlpha == 0)
			{
				m_isUp = false;
				m_isEndProccess = true;
			}
		}
		else {
			if (m_ColorAlpha != 255)
			{
				m_ColorAlpha++;
				m_isEndProccess = true;
			}
		}
		m_CurrentTime -= m_TimeSleep;
	}
	m_LayerColor.setFillColor(sf::Color(m_Color.r, m_Color.b, m_Color.g, m_ColorAlpha));
}

void ShadowWindow::Draw(sf::RenderWindow* window)
{
	window->draw(m_LayerColor);
}

void ShadowWindow::setLight(bool isLight)
{
	m_isUp = isLight;
}

bool ShadowWindow::isEnd()
{
	return m_isEndProccess;
}

void ShadowWindow::setColor(sf::Color color)
{
	m_Color = color;
}
