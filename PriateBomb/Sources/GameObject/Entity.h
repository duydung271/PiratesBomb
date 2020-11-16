#pragma once
#include "World.h"
enum ENTITY
{
	ENTITY_PLAYER=0,
	ENTITY_BOMB,
	ENTITY_GROUND,
};
class Entity
{
public:
	Entity();
	virtual ~Entity();
	void setActive(bool state);
	bool isActive();
	void setBody(b2Body* body);
	void Tag(ENTITY);
	b2Body* getBody();
protected:
	bool m_Active;
	b2Body* m_Body;
	ENTITY m_Tag;
	sf::Vector2f m_Velocity;

};