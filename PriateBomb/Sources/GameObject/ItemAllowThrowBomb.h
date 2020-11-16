#pragma once
#include "Item.h"
class ItemAllowThrowBomb :public Item
{
public:
	ItemAllowThrowBomb();
	~ItemAllowThrowBomb();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:

};