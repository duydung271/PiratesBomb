#pragma once
#include "IBullet.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "ExplosionEffect.h"


class Bullet:
	public IBullet,public Entity, public sf::CircleShape
{
public:
	Bullet();
	virtual ~Bullet();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void setNextState(STATE_BULLET newState);
	void performAction();
	b2Body* getBody();
	bool isCollision();
	Entity* getEntity();

	void setDamge(float damge);

private:
	IBulletState* m_currentState;
	IBulletState* m_fireState;
	IBulletState* m_explositionState;

	STATE_BULLET m_currentAction;
	STATE_BULLET m_NextAction;

	AttributeComponent* m_Attribute;
};