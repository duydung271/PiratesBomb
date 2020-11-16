#pragma once
#include "Item.h"
class ItemSpeed :public Item
{
public:
	ItemSpeed();
	~ItemSpeed();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:

};