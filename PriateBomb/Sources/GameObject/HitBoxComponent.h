#pragma once
#include "../GameManager/ResourceManager.h"

class HitBoxComponent
	:public sf::RectangleShape
{
public:
	HitBoxComponent(sf::Vector2f pos, sf::Vector2f size);
	HitBoxComponent(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f offSet);
	~HitBoxComponent();

	void Update(float deltaTime);

	b2Body* Body;
	bool isOnGround;
};