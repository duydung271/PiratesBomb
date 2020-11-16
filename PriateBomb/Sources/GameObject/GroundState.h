#pragma once
#include "IPState.h"
#include "IPlayer.h"

class GroundPState
	:public IPState
{
public:
	GroundPState(IPlayer* player);
	~GroundPState();
	void Init();
	void Draw(sf::RenderWindow* window);
	void Update(float deltaTime);

private:
	IPlayer* m_Player;
	bool m_isGround;
	bool m_isEnd;
	AnimationComponent* m_Animation;
};