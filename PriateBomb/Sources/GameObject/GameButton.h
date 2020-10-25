#pragma once
#include "../GameManager/ResourceManager.h"

class GameButton
	:public sf::Drawable, public sf::Transformable
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
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform = getTransform();
		target.draw(*m_Sprite,states);
	}
	void	(*m_pBtClick)();
	bool	m_isHandle;
	sf::Sprite* m_Sprite;
	float m_CurrentTime;
	float m_TimeRelease;
	static sf::RenderWindow* m_Window;
};
//Set Window before using HandleTouchEvents
// it will get mouse position in the window