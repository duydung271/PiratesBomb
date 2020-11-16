#include "HearBar.h"

HeartBar::HeartBar()
{
	m_BarBack.setSize(sf::Vector2f(11, 2));
	m_BarAbove.setSize(sf::Vector2f(10, 1));
	m_BarAbove.setFillColor(sf::Color::Red);
	m_OffSet = sf::Vector2f(0, 0);
}

HeartBar::~HeartBar()
{
	m_Attribute = nullptr;
	if (m_Box != nullptr)
	{
		delete m_Box;
	}
	m_Box = nullptr;
}

void HeartBar::Init()
{
	sf::Vector2f size(m_Box->getRadius()*2.f, m_Box->getRadius());
	size.y = 5.f;
	m_BarBack.setSize(size);
	m_BarAbove.setSize(size);

	m_BarAbove.setOrigin(m_BarAbove.getSize() * 0.5f);
	m_BarBack.setOrigin(m_BarAbove.getSize() * 0.5f);
	m_Size = size;
}

void HeartBar::Update(float deltaTime)
{
	sf::Vector2f size(m_Attribute->getHp() / m_Attribute->getMaxHP() * m_Size.x, m_Size.y);
	sf::Vector2f pos = m_Box->getPosition();
	pos.y -= 20;
	pos.x += m_OffSet.x;
	pos.y += m_OffSet.y;

	m_BarBack.setPosition(pos);
	m_BarAbove.setPosition(pos);
	m_BarAbove.setSize(size);
}

void HeartBar::Draw(sf::RenderWindow* window)
{
	window->draw(m_BarBack);
	window->draw(m_BarAbove);
}

void HeartBar::setEntity(sf::CircleShape *box)
{
	m_Box = box;
}

void HeartBar::setAttribute(AttributeComponent* newAttribute)
{
	m_Attribute = newAttribute;
}

void HeartBar::setOffSet(sf::Vector2f offset)
{
	m_OffSet = offset;
}

void HeartBar::setSize(sf::Vector2f size)
{
	m_Size = size;
	m_BarBack.setSize(m_Size);
	m_BarAbove.setSize(m_Size);
}
