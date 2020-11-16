#pragma once
#include "../GameManager/ResourceManager.h"

class Cloud
{
public:
	void Init(std::string name);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void setPosition(sf::Vector2f pos);
	void setScale(sf::Vector2f scale);
	void setSpeed(sf::Vector2f speed);
private:
	sf::Sprite m_Cloud;
	sf::Vector2f m_Speed;
	sf::Vector2f m_SavePoint;
};