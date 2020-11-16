#pragma once
#include "../GameManager/ResourceManager.h"

class HitCircleComponent
	:public sf::CircleShape
{
public:
	HitCircleComponent(sf::Vector2f pos, float radius);
	HitCircleComponent(sf::Vector2f pos, float radius, float offSet);
	~HitCircleComponent();

	void Update(float deltaTime);

	b2Body* Body;
	bool isOnGround;
};