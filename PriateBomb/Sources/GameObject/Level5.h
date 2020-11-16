#pragma once
#include "ILevel.h"
#include "MonsterManager.h"

class Level5 : public ILevel
{
public:
	Level5();
	~Level5();
	void Init(IPlayer* player);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void Reset();
	bool isNeedNextLevel();
private:
	IPlayer* m_Player;
	MonsterManager* m_MonsterManager;
};