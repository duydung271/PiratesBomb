#pragma once
#include <Box2D/Box2D.h>
#include "../GameManager/Singleton.h"
#include <SFML/System/Vector2.hpp>
#include "CollisionManager.h"

static const float SCALE = 30.f;
class World
	:public CSingleton<World>
{
public:
	b2World* GetWorld();
	void setWorld(b2World* newWorld);
	b2Body* CreateGround(b2Vec2 pos, b2Vec2 size);
	b2Body* CreateBox(b2Vec2 pos, b2Vec2 size);
	b2Body* CreateBall(b2Vec2 pos, float radius);
	static b2Vec2 ConvertToPM(sf::Vector2f vt);
	static sf::Vector2f ConvertToPixal(b2Vec2 vt);

private:
	static b2World* m_World;
	
};