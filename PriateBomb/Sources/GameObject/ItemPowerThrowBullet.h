#pragma once
#include "Item.h"
class ItemPowerThrowBullet :public Item
{
public:
	ItemPowerThrowBullet();
	~ItemPowerThrowBullet();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:

};