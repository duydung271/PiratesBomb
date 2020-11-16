#include "Cloud.h"

void Cloud::Init(std::string name)
{
	m_Cloud.setTexture(*ResourceManagers::GetInstance()->GetTexture(name));
	m_Speed = sf::Vector2f(-60.f, 0.f);
}

void Cloud::Update(float deltaTime)
{
	if (m_Cloud.getPosition().x <= -1000.f) m_Cloud.setPosition(m_SavePoint);
	m_Cloud.move(m_Speed*deltaTime);
}

void Cloud::Draw(sf::RenderWindow* window)
{
	window->draw(m_Cloud);
}

void Cloud::setPosition(sf::Vector2f pos)
{
	m_Cloud.setPosition(pos);
	m_SavePoint = pos;
}

void Cloud::setScale(sf::Vector2f scale)
{
	m_Cloud.setScale(scale);
}

void Cloud::setSpeed(sf::Vector2f speed)
{
	m_Speed = speed;
}
