#pragma once
#include "Item.h"
class ItemDamgeBomb :public Item
{
public:
	ItemDamgeBomb();
	~ItemDamgeBomb();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:

};