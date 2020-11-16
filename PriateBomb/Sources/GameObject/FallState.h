#pragma once
#include "IPState.h"
#include "IPlayer.h"

class FallPState
	:public IPState
{
public:
	FallPState(IPlayer* player);
	void Init();
	void Draw(sf::RenderWindow* window);
	void Update(float deltaTime);

private:
	IPlayer* m_Player;
};