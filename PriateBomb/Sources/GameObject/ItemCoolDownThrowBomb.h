#pragma once
#include "Item.h"
class ItemCoolDownThrowBomb :public Item
{
public:
	ItemCoolDownThrowBomb();
	~ItemCoolDownThrowBomb();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:

};