#pragma once
#include "AttributeItem.h"
#include "AttributeComponent.h"
#include "../GameManager/ResourceManager.h"
#include "ItemConfig.h"

class Item:public AttributeItem, public sf::CircleShape
{
public:
	Item();
	virtual ~Item();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Draw(sf::RenderWindow* window);
	virtual void Collising();
	b2Body* getBody();
	void Born();
	bool isBorn();
	void Reset();
	void setBody(b2Body* newBody);

protected:
	AnimationComponent* m_CurrentAnimation;
	AnimationComponent* m_AniIdle;
	AnimationComponent* m_AniCollected;

	b2Body* m_Body;
	void CreateBody();

	bool m_isBorn;
};