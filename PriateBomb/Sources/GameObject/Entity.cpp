#include "Entity.h"

Entity::Entity()
{
    m_Active = false;
}

Entity::~Entity()
{
    if (m_Body != nullptr)
    {
        World::GetInstance()->GetWorld()->DestroyBody(m_Body);
    }
    m_Body = nullptr;
}

void Entity::setActive(bool state)
{
    m_Active = state;
}

bool Entity::isActive()
{
    return m_Active;
}

void Entity::setBody(b2Body* body)
{
    m_Body = body;
}

void Entity::Tag(ENTITY tag)
{
    m_Tag = tag;
    switch (tag)
    {
    case ENTITY_PLAYER:
        break;
    case ENTITY_BOMB:
        break;
    case ENTITY_GROUND:
        break;
    default:
        break;
    }
}

b2Body* Entity::getBody()
{
    return m_Body;
}
