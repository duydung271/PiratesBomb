#pragma once
#include "IPState.h"
#include "IPlayer.h"

class DeadGroundState
	:public IPState
{
public:
	DeadGroundState(IPlayer* player);
	void Init();
	void Draw(sf::RenderWindow* window);
	void Update(float deltaTime);

private:
	IPlayer* m_Player;
	bool m_isEnd;
};