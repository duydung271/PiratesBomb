#include "World.h"

b2World* World::m_World = nullptr;

b2World* World::GetWorld()
{
	return m_World;
}

void World::setWorld(b2World* newWorld)
{
	m_World = newWorld;
}

b2Body* World::CreateGround(b2Vec2 pos, b2Vec2 size)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(pos.x / SCALE, pos.y / SCALE);
	BodyDef.type = b2_staticBody;
	b2Body* Body = m_World->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((size.x / 2) / SCALE, (size.y / 2) / SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.filter.categoryBits = CATEGORY_GROUND;
	FixtureDef.filter.maskBits = MASK_GROUND;
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
	return Body;
}

b2Body* World::CreateBox(b2Vec2 pos, b2Vec2 size)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(pos.x / SCALE, pos.y / SCALE);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation=true;
	b2Body* Body = m_World->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((size.x / 2) / SCALE, (size.y / 2) / SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
	return Body;
}

b2Body* World::CreateBall(b2Vec2 pos,	float  radius)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(pos.x / SCALE, pos.y / SCALE);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;
	b2Body* Body = m_World->CreateBody(&BodyDef);

	b2CircleShape Shape;
	Shape.m_radius = radius / SCALE;
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	FixtureDef.filter.categoryBits = CATEGORY_PLAYER;
	FixtureDef.filter.maskBits = MASK_PLAYER;
	Body->CreateFixture(&FixtureDef);
	return Body;
}

b2Vec2 World::ConvertToPM(sf::Vector2f vt)
{
	return b2Vec2(vt.x / SCALE, vt.y / SCALE);
}

sf::Vector2f World::ConvertToPixal(b2Vec2 vt)
{
	return sf::Vector2f(vt.x*SCALE,vt.y*SCALE);
}
