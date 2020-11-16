#pragma once
#include "../GameObject/Level1.h"
#include "../GameObject/Level2.h"
#include "../GameObject/Level3.h"
#include "../GameObject/Level4.h"
#include "../GameObject/Level5.h"

class LevelManager
{
public:
	enum LEVEL
	{
		LEVEL_1=0,
		LEVEL_2,
		LEVEL_3,
		LEVEL_4,
		LEVEL_5,
		LEVEL_NULL,
	};
	~LevelManager();
	void Init(IPlayer* player);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void ChangeNextLevel(LEVEL next);
	void NextLevel();
	void PerformLevel();
	LEVEL getLevel();
private:
	LEVEL m_LEVELth;
	std::vector<ILevel*> m_Level;
	ILevel* m_currentLevel;
	
	LEVEL m_nextLevel;

	float m_currentTime;
	float m_timeChange;

	bool m_isEndLevel;
};