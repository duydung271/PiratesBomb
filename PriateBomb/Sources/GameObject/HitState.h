#pragma once
#include "IPState.h"
#include "IPlayer.h"

class HitState
	:public IPState
{
public:
	HitState(IPlayer* player);
	void Init();
	void Draw(sf::RenderWindow* window);
	void Update(float deltaTime);

private:
	IPlayer* m_Player;
	bool m_isEnd;
};