#pragma once
#include "MouseDirect.h"
#include "Bullet.h"
#include "../GameStates/GameStateBase.h"

class Rocket: public sf::RectangleShape
{
public:
	Rocket();
	~Rocket();
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow *window);
	Bullet* getBullet();
	void Fire();
	void setPostion(b2Vec2 pos);
	void setTimeSkill(float timeSkill);
	void setDamge(float Damge);
	void setSpeed(float power);

private:
	MouseDirect m_MouseDirect;
	std::list<Bullet*> m_BulletList;
	int m_Num;
	float m_Power;
	b2Vec2 m_Pos;
	float m_CurrentTime;
	float m_TimeSkill;
	bool m_isFire;

	float m_Damge;
};