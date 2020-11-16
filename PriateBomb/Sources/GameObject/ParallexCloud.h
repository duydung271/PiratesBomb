#pragma once
#include "../GameManager/ResourceManager.h"

class ParallexCloud
{
public:
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void Reset();
private:
	sf::RectangleShape m_layer1;
	sf::RectangleShape m_layer2;
	sf::Vector2f m_Speed;
	sf::Vector2f m_SavePoint;
};