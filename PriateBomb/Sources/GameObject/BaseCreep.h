#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "MovingDirect.h"
#include "HearBar.h"
#include "ItemManager.h"
#include "DataGamePlay.h"

enum BASE_CREEP_STATE
{
	RUN=0,
	HIT,
	STATE_NULL,
};

class BaseCreep:
	public Entity,public sf::CircleShape//,public sf::RectangleShape
{
public:
	BaseCreep();
	virtual ~BaseCreep();
	void setTarget(sf::Vector2f target);
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Draw(sf::RenderWindow *window);

	virtual void setNextState(BASE_CREEP_STATE newState);
	virtual void performState();
	virtual void Reset();
	virtual void Awake();
	virtual void ResetAll();
	virtual void CountDead()=0;
	virtual void CountBorn()=0;

protected:
	void CreateBody();
	sf::Vector2f m_NextPoint;
	bool m_isMovingToNext;
	MovingDirect m_MovingDirect;

	float m_currentTime;
	float m_timeChangeTarger;
	float m_Speed;

	AnimationComponent* m_AniRun;
	AnimationComponent* m_AniHit;
	AnimationComponent* m_CurrentAni;

	HeartBar* m_HearBar;
	AttributeComponent* m_Attribute;

	BASE_CREEP_STATE m_CurrentAction;
	BASE_CREEP_STATE m_NextAction;

	bool m_wasCreatedItem;
};