#pragma once
#include "AttributeComponent.h"
#include "Entity.h"
#include "../GameManager/ResourceManager.h"

class HeartBar
{
public:
	HeartBar();
	~HeartBar();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void setEntity(sf::CircleShape *box);
	void setAttribute(AttributeComponent* newAttribute);
	void setOffSet(sf::Vector2f offset);
	void setSize(sf::Vector2f size);
private:
	AttributeComponent* m_Attribute;
	sf::CircleShape *m_Box;
	sf::RectangleShape m_BarBack;
	sf::RectangleShape m_BarAbove;

	sf::Vector2f m_OffSet;

	sf::Vector2f m_Size;
};