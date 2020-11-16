#pragma once
#include "Item.h"
class ItemHeart:public Item
{
public:
	ItemHeart();
	~ItemHeart();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:

};