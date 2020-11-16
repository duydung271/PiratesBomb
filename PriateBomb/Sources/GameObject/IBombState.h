#pragma once
#include "IBomb.h"

class IBombState
{
public:
	virtual void Init() = 0;
	virtual void Update(const float deltaTime) = 0;
	virtual void Draw(sf::RenderWindow* window) = 0;
};