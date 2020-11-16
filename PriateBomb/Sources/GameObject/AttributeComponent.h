#pragma once
#include "SFML/Graphics.hpp"

class AttributeComponent
{
public:
	AttributeComponent();
	virtual ~AttributeComponent();
	void LoseHP(float offset);
	int getHp();
	void setHP(float hp);
	void HealHP(float offset);

	void setMaxHP(float hp);
	float getMaxHP();
	void Update(float deltaTime);
	bool isHit();
	bool isDead();
	bool isStuning();
	void setStuning(bool isStun);

	bool isPush();
	void setIsPush(bool ispush);

	void setDamge(float damge);
	void setVelocity(sf::Vector2f velocity);
	void setDamegeBullet(float DamgeBullet);
	void setTimeThrowBullet(float TimeThrowBullet);
	void setDamgeBomb(float DamgeBomb);
	void setAllowThrowBomb(bool allow);
	void setTimeThrowBomb(float TimeThrowBomb);
	void setPowerThrowBullet(float speed);
	void setPowerThrowBomb(float speed);
	void setCoolDownBomb(float time);

	float getDamge();
	sf::Vector2f getVelocity();
	float getDamgeBullet();
	float getTimeThrowBullet();
	float getDamgeBomb();
	float getTimeThrowBomb();
	bool isAllowThrowBomb();
	float getCoolTimeBomb();
	float getSpeedBomb();
	float getSpeedBullet();

	void UpVelocity(sf::Vector2f offset);
	void CoolDownTimeThrowBullet(float offset);
	void CoolDownTimeThrowBomb(float offset);
	void AllowThrowBomb();
	void UpDamgeBullet(float delta);
	void UpDamgeBomb(float delta);
	void UpPowerThrowBomb(float power);
	void UpPowerThrowBullet(float power);
	void DecreaseCoolDownTimeBomb(float time);
	
private:
	sf::Vector2f m_Velocity;
	float m_DamgeBullet;
	float m_TimeThrowBullet;

	bool m_isAllowThrowBomb;
	float m_TimeThrowBomb;
	float m_DamgeBomb;

	float m_Hp;
	float m_MaxHP;
	bool m_isHit;

	bool m_isPush;
	bool m_isStuning;
	float m_Damge;//Damge cua vat the gay ra cho doi tuong khac

	float m_CoolDownTimeBomb;
	float m_PowerThrowBullet;
	float m_PowerThrowBomb;

	
};