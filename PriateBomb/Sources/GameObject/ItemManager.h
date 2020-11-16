#pragma once
#include "ItemLib.h"
#include <list>
#include "../GameManager/Singleton.h"
enum ITEM
{
	ITEM_AllowThrowBomb = 0,
	ITEM_CoolDownThrowBomb,
	ITEM_CoolDownThrowBullet,
	ITEM_CoolDownTimeBomb,
	ITEM_DamgeBomb,
	ITEM_DamgeBullet,
	ITEM_Heart,
	ITEM_Jump,
	ITEM_PowerThrowBomb,
	ITEM_PowerThrowBullet,
	ITEM_Speed,
	ITEM_NUM,
};
class ItemManager:public CSingleton<ItemManager>
{
public:
	ItemManager();
	~ItemManager();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void BornItem();
	void BornItem(sf::Vector2f pos);
	Item* getRandomItem();
	Item* CreateItem(ITEM type);

	void Reset();

private:
	float m_CurrentTime;
	std::vector<Item*> m_ListItem;
	int m_Num;
	float m_TimeBorn;

	bool m_isInit;

};