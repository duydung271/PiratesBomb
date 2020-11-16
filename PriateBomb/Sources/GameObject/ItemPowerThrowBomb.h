#pragma once
#include "Item.h"
class ItemPowerThrowBomb :public Item
{
public:
	ItemPowerThrowBomb();
	~ItemPowerThrowBomb();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:

};