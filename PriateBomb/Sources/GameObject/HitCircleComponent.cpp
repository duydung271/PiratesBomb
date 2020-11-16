#include "HitCircleComponent.h"

HitCircleComponent::HitCircleComponent(sf::Vector2f pos, float radius)
{
	setRadius(radius);
	setPosition(pos);
	setFillColor(sf::Color(110, 110, 110));
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(1.f);
	Body = World::GetInstance()->CreateBall(b2Vec2(pos.x,pos.y), radius);
	setOrigin(radius, radius);
}

HitCircleComponent::HitCircleComponent(sf::Vector2f pos, float radius, float offSet)
{
	setRadius(radius-offSet);
	setPosition(pos);
	setFillColor(sf::Color(0, 0, 0, 0));
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(1.f);
	Body = World::GetInstance()->CreateBall(b2Vec2(pos.x, pos.y), radius-offSet);
	setOrigin(radius-offSet, radius-offSet);
}

HitCircleComponent::~HitCircleComponent()
{
	World::GetInstance()->GetWorld()->DestroyBody(Body);
}

void HitCircleComponent::Update(float deltaTime)
{
	this->setPosition(World::ConvertToPixal(Body->GetPosition()));
	this->setRotation(180 / b2_pi * Body->GetAngle());
}
