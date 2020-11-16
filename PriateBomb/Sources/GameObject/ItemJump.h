#pragma once
#include "Item.h"
class ItemJump :public Item
{
public:
	ItemJump();
	~ItemJump();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:

};