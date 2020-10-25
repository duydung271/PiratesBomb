#include "AnimationComponent.h"

AnimationComponent::AnimationComponent()
{
	m_currentFrame = sf::Vector2u(0,0);
	m_posUV = sf::Vector2i(0, 0);
	
}

AnimationComponent::~AnimationComponent()
{
	m_FrameData = nullptr;
	if (m_Sprite != nullptr)
	{
		delete m_Sprite;
		m_Sprite = nullptr;
	}
}

void AnimationComponent::Init(const std::string& name)
{

	m_Sprite = new sf::Sprite();
	m_Sprite->setTexture(*ResourceManagers::GetInstance()->GetTexture(name));
	m_FrameData = ResourceManagers::GetInstance()->GetFrameData(name);
	m_Size = sf::Vector2u(m_FrameData->Width / m_FrameData->NumFrame.x, m_FrameData->Height / m_FrameData->NumFrame.y);
}

void AnimationComponent::Update(const float& deltaTime)
{
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
	m_Sprite->setTextureRect(sf::IntRect(m_posUV, (sf::Vector2i)m_Size));

}

bool AnimationComponent::isEndFrame()
{
	return m_currentFrame.x == (m_FrameData->NumFrameInRow[m_currentFrame.y] - 1);
}

void AnimationComponent::Reset()
{
	m_currentFrame.x = 0;
	m_currentTime=0.f;
}

void AnimationComponent::setState(int newState)
{
	m_currentFrame.y = newState;
	Reset();
}

