#include "LayerShadow.h"

LayerShadow::LayerShadow()
{
	m_alphaMax = 255;
	m_alphaMin = 0;
	m_FrameTime = 0.3f;
	m_CurrentTime = 0.f;
	m_alphaIsUp = true;
	m_CurrentAlpha = 0;
	this->setSize(sf::Vector2f(screenWidth, screenHeight));
}

LayerShadow::~LayerShadow()
{
}

void LayerShadow::setAlphaMax(int alpha)
{
	m_alphaMax = alpha;
}

void LayerShadow::setAlphaMin(int alpha)
{
	m_alphaMin = alpha;
}

void LayerShadow::Update(float deltaTime)
{
	m_CurrentTime += deltaTime;
	if (m_CurrentTime >= m_FrameTime)
	{
		if (m_alphaIsUp)
		{
			if (m_CurrentAlpha<m_alphaMax) m_CurrentAlpha++;
		}
		else
		{
			if (m_CurrentAlpha > m_alphaMin) m_CurrentAlpha--;
		}
	}
	sf::Color color = this->getFillColor();
	this->setFillColor(sf::Color(color.r, color.b, color.g, m_CurrentAlpha));
}

void LayerShadow::setDir(bool alphaIsUp)
{
	m_alphaIsUp = alphaIsUp;
	if (alphaIsUp == false) m_CurrentAlpha = m_alphaMax;
	else m_CurrentAlpha = m_alphaMin;
	sf::Color color = this->getFillColor();
	this->setFillColor(sf::Color(color.r, color.b, color.g, m_CurrentAlpha));
}

bool LayerShadow::isEnd()
{
	if (m_alphaIsUp)
	{
		return m_CurrentAlpha >= m_alphaMax;
	}
	else return m_CurrentAlpha <= m_alphaMin;
	
}

bool LayerShadow::alphaIsUp()
{
	return m_alphaIsUp;
}
