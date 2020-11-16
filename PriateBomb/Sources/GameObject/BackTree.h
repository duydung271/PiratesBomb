#pragma once
#include "../GameManager/ResourceManager.h"
class BackTree
{
public:
	BackTree();
	~BackTree();
	void Init(std::string name);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void setPosition(sf::Vector2f pos);
private:
	AnimationComponent* m_Ani;
};