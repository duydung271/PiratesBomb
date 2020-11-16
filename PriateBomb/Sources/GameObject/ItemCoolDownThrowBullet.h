#pragma once
#include "Item.h"
class ItemCoolDownThrowBullet :public Item
{
public:
	ItemCoolDownThrowBullet();
	~ItemCoolDownThrowBullet();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:

};