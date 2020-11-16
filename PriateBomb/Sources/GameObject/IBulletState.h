#pragma once
#include <SFML/Graphics.hpp>
#include "IBullet.h"
#include "AnimationComponent.h"

class IBulletState
{
public:
	virtual void Init() = 0;
	virtual void Update(const float deltaTime) = 0;
	virtual void Draw(sf::RenderWindow* window) = 0;
	virtual void setTransform(sf::Vector2f pos, float angle) = 0;
};