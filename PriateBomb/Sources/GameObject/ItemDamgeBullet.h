#pragma once
#include "Item.h"
class ItemDamgeBullet :public Item
{
public:
	ItemDamgeBullet();
	~ItemDamgeBullet();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:

};