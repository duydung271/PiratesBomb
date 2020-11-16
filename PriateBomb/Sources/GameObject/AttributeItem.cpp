#include "AttributeItem.h"

AttributeItem::AttributeItem()
{
    m_ExHp = 0.f;
    m_ExDamgeBomb = 0.f;
    m_ExDamgeBullet=0.f;
    m_ExVelocity = sf::Vector2f(0, 0);
    m_isActive = false;
    m_isAllowThrowBomb = false;
    m_isUsed = false;
    m_TimeThrowBomb = 0.f;
    m_TimeThrowBullet = 0.f;
}

AttributeItem::~AttributeItem()
{
}

void AttributeItem::setExHp(float exHP)
{
    m_ExHp = exHP;
}

float AttributeItem::getExHp()
{
    return m_ExHp;
}

sf::Vector2f AttributeItem::getExVelocity()
{
    return m_ExVelocity;
}

void AttributeItem::setExVelocity(sf::Vector2f velocity)
{
    m_ExVelocity = velocity;
}

float AttributeItem::getExDamgeBullet()
{
    return m_ExDamgeBullet;
}

void AttributeItem::setExDamegeBullet(float exDamgeBullet)
{
    m_ExDamgeBullet = exDamgeBullet;
}

float AttributeItem::getTimeThrowBullet()
{
    return m_TimeThrowBullet;
}

void AttributeItem::setTimeThrowBullet(float TimeThrowBullet)
{
    m_TimeThrowBullet = TimeThrowBullet;
}

bool AttributeItem::isAllowThrowBomb()
{
    return m_isAllowThrowBomb;
}

void AttributeItem::setAllowThrowBomb(bool allow)
{
    m_isAllowThrowBomb = allow;
}

void AttributeItem::setTimeThrowBomb(float TimeThrowBomb)
{
    m_TimeThrowBomb = TimeThrowBomb;
}

void AttributeItem::setExDamgeBomb(float ExDamgeBomb)
{
    m_ExDamgeBomb = ExDamgeBomb;
}

void AttributeItem::setCoolDownTimeBomb(float time)
{
    m_CoolDownTimeBomb = time;
}

void AttributeItem::setPowerThrowBomb(float power)
{
    m_PowerThrowBomb = power;
}

void AttributeItem::setPowerThrowBullet(float power)
{
    m_PowerThrowBullet = power;
}

float AttributeItem::getExDamgeBomb()
{
    return m_ExDamgeBomb;
}

float AttributeItem::getTimeThrowBomb()
{
    return m_TimeThrowBomb;
}

float AttributeItem::getCoolDownTimeBomb()
{
    return m_CoolDownTimeBomb;
}

float AttributeItem::getPowerThrowBomb()
{
    return m_PowerThrowBomb;
}

float AttributeItem::getPowerThrowBullet()
{
    return m_ExDamgeBullet;
}



void AttributeItem::setActive(bool isActive)
{
    m_isActive = isActive;
}

bool AttributeItem::isActive()
{
    return m_isActive;
}

bool AttributeItem::isUsed()
{
    return m_isUsed;
}

void AttributeItem::setIsUsed(bool isUsed)
{
    m_isUsed = isUsed;
}
