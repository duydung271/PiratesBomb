#include "ParallexCloud.h"

void ParallexCloud::Init()
{
	sf::Vector2f size(screenWidth, screenHeight);
	size.y -= 400;
	size.x += 5;
	float posY=210;
	m_layer1.setSize(size);
	m_layer2.setSize(size);
	m_layer1.setPosition(sf::Vector2f(0.f, posY));
	m_layer2.setPosition(sf::Vector2f(screenWidth, posY));

	m_layer1.setTexture(ResourceManagers::GetInstance()->GetTexture("Big Clouds"));
	m_layer2.setTexture(ResourceManagers::GetInstance()->GetTexture("Big Clouds"));
	m_Speed = sf::Vector2f(-30.f, 0.f);

	m_SavePoint = sf::Vector2f(0.f, posY);

}

void ParallexCloud::Update(float deltaTime)
{
	if (m_layer2.getPosition().x <= 0.f)
	{
		Reset();
	}
	m_layer1.move(m_Speed * deltaTime);
	m_layer2.move(m_Speed * deltaTime);
}

void ParallexCloud::Draw(sf::RenderWindow* window)
{
	window->draw(m_layer1);
	window->draw(m_layer2);
}

void ParallexCloud::Reset()
{
	m_layer1.setPosition(m_SavePoint);
	m_layer2.setPosition(m_SavePoint.x+screenWidth,m_SavePoint.y);
}
