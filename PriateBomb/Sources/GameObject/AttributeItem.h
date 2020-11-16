#pragma once
#include "../GameManager/ResourceManager.h"
class AttributeItem
{
public:
	AttributeItem();
	virtual ~AttributeItem();

	float getTimeThrowBullet();
	float getExHp();
	sf::Vector2f getExVelocity();
	float getExDamgeBullet();
	bool isAllowThrowBomb();
	float getExDamgeBomb();
	float getTimeThrowBomb();
	float getCoolDownTimeBomb();
	float getPowerThrowBomb();
	float getPowerThrowBullet();

	void setExDamegeBullet(float exDamgeBullet);
	void setExVelocity(sf::Vector2f velocity);
	void setTimeThrowBullet(float TimeThrowBullet);
	void setExHp(float exHP);
	void setAllowThrowBomb(bool allow);
	void setTimeThrowBomb(float TimeThrowBomb);
	void setExDamgeBomb(float ExDamgeBomb);
	void setCoolDownTimeBomb(float time);
	void setPowerThrowBomb(float power);
	void setPowerThrowBullet(float power);
	
	


	void setActive(bool isActive);
	bool isActive();

	bool isUsed();
	void setIsUsed(bool isUsed);



protected:
	float m_ExHp;
	sf::Vector2f m_ExVelocity;
	float m_ExDamgeBullet;
	float m_TimeThrowBullet;

	bool m_isAllowThrowBomb;
	float m_TimeThrowBomb;
	float m_ExDamgeBomb;

	float m_CoolDownTimeBomb;
	float m_PowerThrowBomb;
	float m_PowerThrowBullet;

	bool m_isActive;
	bool m_isUsed;
};