#include "WaterReflect.h"

WaterReflect::WaterReflect()
{
}

WaterReflect::~WaterReflect()
{
	if (m_Water != nullptr)
	{
		delete m_Water;
		m_Water = nullptr;
	}
}

void WaterReflect::Init(std::string name)
{
	m_Water = new AnimationComponent();
	m_Water->Init(name);
	m_Water->setScale(2.f, 2.f);
}

void WaterReflect::Update(float deltaTime)
{
	m_Water->Update(deltaTime);
}

void WaterReflect::Draw(sf::RenderWindow *window)
{
	window->draw(*m_Water);
}

void WaterReflect::setPositison(sf::Vector2f pos)
{
	m_Water->setPosition(pos);
}
