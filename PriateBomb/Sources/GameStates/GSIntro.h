#pragma once
#include "GameStateBase.h"
#include "../GameObject/GameButton.h"
#include "../GameObject/ShadowWindow.h"


class GSIntro
	:public GameStateBase
{
public:
	GSIntro();
	virtual ~GSIntro();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(const float& dt);
	void Render();

	void LoadingAllDate();
private:
	float m_CurrentTime;
	sf::Sprite m_BackGround;
	sf::RectangleShape m_Meo;
	sf::RectangleShape m_Logo;
	sf::Color m_ColorLogo;
	sf::Color m_ColorMeo;
	
	ShadowWindow m_Shadow;
	bool m_uplogo;
	bool m_NeedChangeNextState;
	LayerShadow m_Layer;

	GameButton* BUG;
	
};
