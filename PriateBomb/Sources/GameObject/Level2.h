#pragma once
#include "ILevel.h"

class Level2 : public ILevel
{
public:
	Level2();
	~Level2();
	void Init(IPlayer* player);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void Reset();
	bool isNeedNextLevel();
private:
	CreepBatManager* m_CreepBatManager;
	CreepBeeManager* m_CreepBeeManager;
	CreepBlueBirdManager* m_CreepBlueBirdManager;

	IPlayer* m_Player;
};