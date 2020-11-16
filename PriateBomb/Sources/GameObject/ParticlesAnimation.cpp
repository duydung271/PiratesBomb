#include "ParticlesAnimation.h"

ParticlesAnimation::ParticlesAnimation()
{
}

void ParticlesAnimation::Init(std::string name)
{
	m_Size = sf::Vector2u(30.f, 30.f);
	this->setTexture(*ResourceManagers::GetInstance()->GetTexture(name));
	this->setOrigin((sf::Vector2f)m_Size * 0.5f);
}

void ParticlesAnimation::setOffSet(sf::Vector2f offset)
{
	m_offSet = offset;
}

void ParticlesAnimation::Update(float deltaTime)
{
	AnimationComponent::Update(deltaTime);
}
