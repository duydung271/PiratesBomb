#pragma once
#include "IBomb.h"
#include "IBombState.h"

class Bomb
	:public Entity, public sf::CircleShape,public IBomb
{
public:
	Bomb();
	~Bomb();

	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow *window);

	AnimationComponent* GetAnimation();
	void setNextState(STATE newState);

	void SetAction();
	void SetState(IBombState* newState);
	b2Body* GetBody();

	void setDamge(float damge);
	float getCoolDownTime();
	void setCoolDownTime(float time);

private:
	AnimationComponent* m_Animation;
	AttributeComponent* m_Attribute;
	STATE m_CurrentAction;
	STATE m_NextState;
	float m_CoolDownTime;

	

	IBombState* m_CurrentState;
	IBombState* m_BombOffState;
	IBombState* m_BombOnState;
	IBombState* m_ExplosionState;

};