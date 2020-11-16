#pragma once
#include "IPState.h"
#include "IPlayer.h"

class JumpAnticipationPState
	:public IPState
{
public:
	JumpAnticipationPState(IPlayer* player);
	void Init();
	void Draw(sf::RenderWindow* window);
	void Update(float deltaTime);

private:
	IPlayer* m_Player;
};