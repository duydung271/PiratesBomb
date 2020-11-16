#pragma once
#include "../GameManager/ResourceManager.h"

class GameButton
	:public sf::RectangleShape
{
public:
	GameButton(std::string nameSprite);
	~GameButton();
	void	SetOnClick(void	(*pBtClick)());
	void	HandleTouchEvents();
	bool	IsHandle();
	void	Update(const float& deltaTime);
	static void	setWindow(sf::RenderWindow* window);
private:
	void	(*m_pBtClick)();
	bool	m_isHandle;
	float m_CurrentTime;
	float m_TimeRelease;

	static sf::RenderWindow* m_Window;

};
//Set Window before using HandleTouchEvents
// it will get mouse position in the window