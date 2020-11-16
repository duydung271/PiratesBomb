#pragma once
#include "GameStateBase.h"
#include "../GameObject/GameButton.h"
#include "../GameObject/BackGround.h"

class GSMenu
	:public GameStateBase
{
public:
	GSMenu();
	virtual ~GSMenu();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(const float& dt);
	void Render();
private:
	sf::RectangleShape* m_BackGround;
	std::list<GameButton* > m_ButtonList;
	AnimationComponent* m_Boss;
	sf::Text m_Text;
	float m_currentTime;
	LayerShadow m_Layer;
	LayerShadow m_LayerOut;
	static StateTypes m_nextState;
	
};
