#pragma once
#include "SFML/Graphics.hpp"
#include "../GameConfig.h"

class ShadowWindow
{
public:
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow *window);
	void setLight(bool isLight);
	bool isEnd();
	void setColor(sf::Color color);
private:
	float m_CurrentTime;
	sf::RectangleShape m_LayerColor;
	float m_TimeSleep;
	int m_ColorAlpha;
	bool m_isUp;

	bool m_isEndProccess;
	sf::Color m_Color;
};