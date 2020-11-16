#pragma once
#include "ILevel.h"

class Level4 : public ILevel
{
public:
	Level4();
	~Level4();
	void Init(IPlayer* player);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void Reset();
	bool isNeedNextLevel();
private:
	Boss* m_Boss;
	CreepSkullManager* m_CreepSkullManager;
	
	IPlayer* m_Player;
};