#pragma once
#include "IPState.h"
#include "IPlayer.h"

class DeadHitState
	:public IPState
{
public:
	DeadHitState(IPlayer* player);
	void Init();
	void Draw(sf::RenderWindow* window);
	void Update(float deltaTime);

private:
	IPlayer* m_Player;
	bool m_isEnd;
};