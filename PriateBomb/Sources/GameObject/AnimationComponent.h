#pragma once
#include "../GameManager/ResourceManager.h"
enum DIRECT
{
	DIRECT_LEFT=0,
	DIRECT_RIGHT,
};

class AnimationComponent
	:public sf::Sprite
{
public:
	AnimationComponent();
	virtual ~AnimationComponent();
	
	virtual void Init(const std::string& name);
	void Update(const float& deltaTime);
	bool isEndFrame();
	void Reset();
	void setState(int newState);
	sf::Vector2u getSize();
	void setDirect(DIRECT newDIRECT);
	inline DIRECT getDirect()
	{
		return m_Direct;
	}

	void Stop();
	void Continue();

protected:
	float m_frameTime;
	sf::Vector2u m_currentFrame;
	float m_currentTime;

	sf::Vector2u m_Size;
	sf::Vector2i m_posUV;

	FrameData* m_FrameData;
	DIRECT m_Direct;
	bool m_isStop;
};