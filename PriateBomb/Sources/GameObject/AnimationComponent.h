#pragma once
#include "../GameManager/ResourceManager.h"

class AnimationComponent
	:public sf::Drawable,sf::Transformable
{
public:
	AnimationComponent();
	virtual ~AnimationComponent();
	
	void Init(const std::string& name);
	void Update(const float& deltaTime);
	bool isEndFrame();
	void Reset();
	void setState(int newState);

protected:
	float m_frameTime;
	sf::Vector2u m_currentFrame;
	float m_currentTime;

	sf::Vector2u m_Size;
	sf::Vector2i m_posUV;
private:
	sf::Sprite* m_Sprite;
	FrameData* m_FrameData;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(*m_Sprite, states);
	}
};