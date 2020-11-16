#pragma once
#include "Item.h"
class ItemCoolDownTimeBomb :public Item
{
public:
	ItemCoolDownTimeBomb();
	~ItemCoolDownTimeBomb();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:

};