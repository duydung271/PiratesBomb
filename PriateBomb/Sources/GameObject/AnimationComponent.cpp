#include "AnimationComponent.h"

AnimationComponent::AnimationComponent()
{
	m_currentFrame = sf::Vector2u(0,0);
	m_posUV = sf::Vector2i(0, 0);
	
}

AnimationComponent::~AnimationComponent()
{
	m_FrameData = nullptr;
}

void AnimationComponent::Init(const std::string& name)
{
	this->setTexture(*ResourceManagers::GetInstance()->GetTexture(name));
	m_FrameData = ResourceManagers::GetInstance()->GetFrameData(name);

	m_Size = sf::Vector2u(m_FrameData->Width / m_FrameData->NumFrame.x, m_FrameData->Height / m_FrameData->NumFrame.y);
	this->setOrigin((sf::Vector2f)m_Size * 0.5f);
}

void AnimationComponent::Update(const float& deltaTime)
{
	if (m_isStop == true) return;
	m_currentTime += deltaTime;
	if (m_currentTime >= m_FrameData->FrameTime[m_currentFrame.y]) {
		m_currentFrame.x++;
		if (m_currentFrame.x == m_FrameData->NumFrameInRow[m_currentFrame.y]) {
			m_currentFrame.x = 0;
		}
		m_currentTime -= m_FrameData->FrameTime[m_currentFrame.y];
	}
	m_posUV.x = m_currentFrame.x * m_Size.x;
	m_posUV.y = m_currentFrame.y * m_Size.y;
	this->setTextureRect(sf::IntRect(m_posUV, (sf::Vector2i)m_Size));

}

bool AnimationComponent::isEndFrame()
{
	return m_currentFrame.x == (m_FrameData->NumFrameInRow[m_currentFrame.y] - 1);
}

void AnimationComponent::Reset()
{
	m_currentFrame.x = 0;
	m_currentTime=0.f;
	m_isStop = false;
}

void AnimationComponent::setState(int newState)
{
	m_currentFrame.y = newState;
	Reset();
}

sf::Vector2u AnimationComponent::getSize()
{
	return m_Size;
}

void AnimationComponent::setDirect(DIRECT newDIRECT)
{
	m_Direct = newDIRECT;
	sf::Vector2f scale(this->getScale());
	if (m_Direct == DIRECT_LEFT)
	{
		
		setScale(-abs(scale.x), scale.y);
	}
	else setScale(abs(scale.x), scale.y);
}

void AnimationComponent::Stop()
{
	m_isStop = true;
}

void AnimationComponent::Continue()
{
	m_isStop = false;
}

