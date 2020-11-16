#pragma once
#include "Bomb.h"
#include <list>
#include "MouseDirect.h"

class BombManager
{
public:
	BombManager();
	~BombManager();
	void setPostion(b2Vec2 pos);
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void Fire();
	Bomb* getBomb();
	void setTimeSkill(float timeSkill);
	void setDamge(float Damge);
	void AllowThrow(bool allow);
	void setSpeed(float power);
	void setCoolDownTime(float time);

private:
	MouseDirect* m_MouseDirect;
	std::list<Bomb*> m_BombList;
	int m_Num;
	float m_Power;
	b2Vec2 m_Pos;
	float m_CurrentTime;
	float m_TimeSkill;
	bool m_isFire;
	float m_Damge;

	bool m_AllowThrow;
	float m_CoolDownTime;
};