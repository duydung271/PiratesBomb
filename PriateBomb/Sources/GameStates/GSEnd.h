#pragma once
#include "GameStateBase.h"
#include "../GameObject/BackGround.h"
#include "../GameObject/GameButton.h"

class GSEnd
	:public GameStateBase
{
public:
	GSEnd();
	virtual ~GSEnd();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(const float& dt);
	void Render();
private:
	std::list<GameButton*> m_ListButton;
	LayerShadow m_LayerLight;
	LayerShadow m_LayerOut;
	static StateTypes m_nextState;
	sf::Text m_Text;


};
