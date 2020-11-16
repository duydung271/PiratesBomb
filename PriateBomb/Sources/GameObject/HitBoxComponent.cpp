#include "HitBoxComponent.h"

HitBoxComponent::HitBoxComponent(sf::Vector2f pos, sf::Vector2f size)
{
	setSize(size);
	setPosition(pos);
	setFillColor(sf::Color(0, 0, 0, 0));
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(1.f);
	Body = World::GetInstance()->CreateBox(b2Vec2(pos.x,pos.y),b2Vec2(size.x,size.y));
	setOrigin(size * 0.5f);
}

HitBoxComponent::HitBoxComponent(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f offSet)
{
	setSize(sf::Vector2f(size.x-offSet.x/2,size.y-offSet.y/2));
	setPosition(pos);
	setFillColor(sf::Color(0, 0, 0, 0));
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(1.f);
	Body = World::GetInstance()->CreateBox(b2Vec2(pos.x, pos.y), b2Vec2(size.x-offSet.x, size.y-offSet.y));
	setOrigin(size * 0.5f);
}

HitBoxComponent::~HitBoxComponent()
{
	World::GetInstance()->GetWorld()->DestroyBody(Body);
}

void HitBoxComponent::Update(float deltaTime)
{
	this->setPosition(World::ConvertToPixal(Body->GetPosition()));
	this->setRotation(180 / b2_pi * Body->GetAngle());
}

