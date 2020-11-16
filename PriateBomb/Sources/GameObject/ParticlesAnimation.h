#pragma once
#include "AnimationComponent.h"
#include "World.h"

class ParticlesAnimation
	:public AnimationComponent
{
public:
	ParticlesAnimation();
	void Init(std::string name);
	void setOffSet(sf::Vector2f offset);
	void Update(float deltaTime);
private:
	sf::Vector2f m_offSet;
};