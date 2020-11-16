#pragma once
#include "IPState.h"
#include "IPlayer.h"

class RunPState
	:public IPState
{
public:
	RunPState(IPlayer* player);
	~RunPState();
	void Init();
	void Draw(sf::RenderWindow* window);
	void Update(float deltaTime);

private:
	IPlayer* m_Player;
	AnimationComponent* m_Animation;
};