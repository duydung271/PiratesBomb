#pragma once
#include "ILevel.h"

class Level1: public ILevel
{
public:
	Level1();
	~Level1();
	void Init(IPlayer* player);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void Reset();
	bool isNeedNextLevel();
private:
	CreepBatManager* m_CreepBatManager;
	IPlayer* m_Player;
};