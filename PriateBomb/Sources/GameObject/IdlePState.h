#pragma once
#include "IPState.h"
#include "IPlayer.h"

class IdlePState
	:public IPState
{
public:
	IdlePState(IPlayer* player);
	void Init();
	void Draw(sf::RenderWindow* window);
	void Update(float deltaTime);

private:
	IPlayer* m_Player;
	float m_CurrentTime;
};