#pragma once
#include "IPState.h"
#include "IPlayer.h"

class JumpPState
	:public IPState
{
public:
	JumpPState(IPlayer* player);
	~JumpPState();
	void Init();
	void Draw(sf::RenderWindow* window);
	void Update(float deltaTime);

private:
	IPlayer* m_Player;
	bool m_isJump;
	bool m_isEnd;
	AnimationComponent* m_Animation;
};