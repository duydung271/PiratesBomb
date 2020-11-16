#pragma once
#include "../GameManager/ResourceManager.h"

class MouseDirect
{
public:
	void Update(float deltaTime, sf::Vector2i pointMouse);
	b2Vec2 getVectorUnit();
	float getAngle();
	void setPointA(sf::Vector2f a);
private:
	float m_Angle;
	b2Vec2 m_VectorUnit;
	sf::Vector2f m_PointA;
};