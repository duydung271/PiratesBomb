#pragma once
#include "../GameManager/ResourceManager.h"

class WaterReflect
{
public:
	WaterReflect();
	~WaterReflect();
	void Init(std::string name);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow *window);
	void setPositison(sf::Vector2f pos);
	
private:
	AnimationComponent* m_Water;
};