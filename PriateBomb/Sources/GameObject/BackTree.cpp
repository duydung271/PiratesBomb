#include "BackTree.h"

BackTree::BackTree()
{
}

BackTree::~BackTree()
{
	if (m_Ani != nullptr)
	{
		delete m_Ani;
	}
	m_Ani = nullptr;
}

void BackTree::Init(std::string name)
{
	m_Ani = new AnimationComponent();
	m_Ani->Init(name);
	m_Ani->setScale(2, 2);
}

void BackTree::Update(float deltaTime)
{
	m_Ani->Update(deltaTime);
}

void BackTree::Draw(sf::RenderWindow* window)
{
	window->draw(*m_Ani);
}

void BackTree::setPosition(sf::Vector2f pos)
{
	m_Ani->setPosition(pos);
}
