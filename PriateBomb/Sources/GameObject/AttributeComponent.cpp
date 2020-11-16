#include "AttributeComponent.h"
#define MinTimeThrow 0.1

AttributeComponent::AttributeComponent()
{
	m_Hp = 0.f;
	m_MaxHP = 0.f;
	m_isHit = false;
	m_isPush = false;
	m_Damge = 0.f;
	m_DamgeBomb = 0.f;
	m_DamgeBullet = 0.f;
	m_isAllowThrowBomb = false;
	m_TimeThrowBomb = 0.f;
	m_TimeThrowBullet = 0.f;
	m_PowerThrowBomb = 0.f;
	m_PowerThrowBullet = 0.f;
	m_CoolDownTimeBomb = 0.f;
}

AttributeComponent::~AttributeComponent()
{
}

void AttributeComponent::LoseHP(float offset)
{
	//m_HpLose = offset;
	m_Hp -= offset;
	if (m_Hp < 0) m_Hp = 0;
	m_isHit = true;
}

int AttributeComponent::getHp()
{
	return m_Hp;
}

void AttributeComponent::setHP(float hp)
{
	m_Hp = hp;
}

void AttributeComponent::HealHP(float offset)
{
	m_Hp += offset;
	if (m_Hp > m_MaxHP) m_Hp = m_MaxHP;
}

void AttributeComponent::setMaxHP(float hp)
{
	m_MaxHP = hp;
	m_Hp = hp;
}

float AttributeComponent::getMaxHP()
{
	return m_MaxHP;
}

void AttributeComponent::Update(float deltaTime)
{
	
	
}

bool AttributeComponent::isHit()
{
	if (m_isHit == true)
	{
		m_isHit = false;
		return true;
	}
	return false;
}

bool AttributeComponent::isDead()
{
	if (m_Hp <= 0)
	{
		m_Hp = 0;
		return true;
	}
	return false;
}

bool AttributeComponent::isStuning()
{
	return m_isStuning;
}

void AttributeComponent::setStuning(bool isStun)
{
	m_isStuning = isStun;
}

bool AttributeComponent::isPush()
{
	return m_isPush;
}

void AttributeComponent::setIsPush(bool ispush)
{
	m_isPush = ispush;
}

void AttributeComponent::setDamge(float damge)
{
	m_Damge = damge;
}

float AttributeComponent::getDamge()
{
	return m_Damge;
}


sf::Vector2f AttributeComponent::getVelocity()
{
	return m_Velocity;
}

void AttributeComponent::setVelocity(sf::Vector2f velocity)
{
	m_Velocity = velocity;
}

float AttributeComponent::getDamgeBullet()
{
	return m_DamgeBullet;
}

void AttributeComponent::setDamegeBullet(float exDamgeBullet)
{
	m_DamgeBullet = exDamgeBullet;
}

float AttributeComponent::getTimeThrowBullet()
{
	return m_TimeThrowBullet;
}

void AttributeComponent::setTimeThrowBullet(float TimeThrowBullet)
{
	m_TimeThrowBullet = TimeThrowBullet;
}

bool AttributeComponent::isAllowThrowBomb()
{
	return m_isAllowThrowBomb;
}

float AttributeComponent::getCoolTimeBomb()
{
	return m_CoolDownTimeBomb;
}

float AttributeComponent::getSpeedBomb()
{
	return m_PowerThrowBomb;
}

float AttributeComponent::getSpeedBullet()
{
	return m_PowerThrowBullet;
}

float AttributeComponent::getTimeThrowBomb()
{
	return m_TimeThrowBomb;
}

void AttributeComponent::setAllowThrowBomb(bool allow)
{
	m_isAllowThrowBomb = allow;
}

void AttributeComponent::setTimeThrowBomb(float TimeThrowBomb)
{
	m_TimeThrowBomb = TimeThrowBomb;
}

void AttributeComponent::setPowerThrowBullet(float speed)
{
	m_PowerThrowBullet = speed;
}

void AttributeComponent::setPowerThrowBomb(float speed)
{
	m_PowerThrowBomb = speed;
}

void AttributeComponent::setCoolDownBomb(float time)
{
	m_CoolDownTimeBomb = time;
}

void AttributeComponent::setDamgeBomb(float ExDamgeBomb)
{
	m_DamgeBomb = ExDamgeBomb;
}

float AttributeComponent::getDamgeBomb()
{
	return m_DamgeBomb;
}

void AttributeComponent::UpVelocity(sf::Vector2f offset)
{
	m_Velocity.x += offset.x;
	m_Velocity.y += offset.y;
}

void AttributeComponent::CoolDownTimeThrowBullet(float offset)
{
	m_TimeThrowBullet -= offset;
	if (m_TimeThrowBullet <= 0.f)
	{
		m_TimeThrowBullet = MinTimeThrow;
	}
}

void AttributeComponent::CoolDownTimeThrowBomb(float offset)
{
	m_TimeThrowBomb -= offset;
	if (m_TimeThrowBomb <= 0.f)
	{
		m_TimeThrowBomb = MinTimeThrow;
	}
}

void AttributeComponent::AllowThrowBomb()
{
	m_isAllowThrowBomb = true;
}

void AttributeComponent::UpDamgeBullet(float delta)
{
	m_DamgeBullet += delta;
}

void AttributeComponent::UpDamgeBomb(float delta)
{
	m_DamgeBomb += delta;
}

void AttributeComponent::UpPowerThrowBomb(float power)
{
	m_PowerThrowBomb += power;
}

void AttributeComponent::UpPowerThrowBullet(float power)
{
	m_PowerThrowBullet += power;
}

void AttributeComponent::DecreaseCoolDownTimeBomb(float time)
{
	m_CoolDownTimeBomb -= time;
	if (m_CoolDownTimeBomb <= 0.f)
	{
		m_CoolDownTimeBomb = 0.1f;
	}
}
