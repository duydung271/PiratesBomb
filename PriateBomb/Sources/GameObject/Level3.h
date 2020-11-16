#pragma once
#include "ILevel.h"

class Level3 : public ILevel
{
public:
	Level3();
	~Level3();
	void Init(IPlayer* player);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void Reset();
	bool isNeedNextLevel();
private:
	CreepSunDragonManager* m_CreepSunDragonManager;
	IPlayer* m_Player;
};