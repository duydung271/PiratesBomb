#include "ItemManager.h"

ItemManager::ItemManager()
{
    m_CurrentTime = 0.f;
    m_Num = 50;
    m_TimeBorn = 40.f;
    m_isInit = false;
    Init();
}

ItemManager::~ItemManager()
{
    for (auto it : m_ListItem)
    {
        if (it != nullptr)
        {
            delete it;
        }
    }
    m_ListItem.clear();
}

void ItemManager::Init()
{
    
    for (auto it : m_ListItem)
    {
        if (it != nullptr)
        {
            delete it;
        }
        it = nullptr;
    }
    m_ListItem.clear();
    for (auto i = 1; i <= m_Num; i++)
    {
        Item* item = CreateItem(static_cast<ITEM>(i%12));
        if (item!=nullptr)
        {
            m_ListItem.push_back(item);
        }
    }

}

void ItemManager::Update(float deltaTime)
{
    m_CurrentTime += deltaTime;
    if (m_CurrentTime >= m_TimeBorn)
    {
        BornItem();
        m_CurrentTime -= m_TimeBorn;
    }
    for (auto it : m_ListItem)
    {
        it->Update(deltaTime);
    }
}

void ItemManager::Draw(sf::RenderWindow* window)
{
    for (auto it : m_ListItem)
    {
        it->Draw(window);
    }
}

void ItemManager::BornItem()
{
    Item* item = getRandomItem();
    if (item == nullptr) return;
    item->Born();
    sf::Vector2f pos(100 + (rand() % 10)*100, 200 + rand() % 100);
    item->getBody()->SetTransform(World::ConvertToPM(pos), 0);
}

void ItemManager::BornItem(sf::Vector2f pos)
{
    Item* item = getRandomItem();
    if (item == nullptr) return;
    item->Born();
    item->getBody()->SetTransform(World::ConvertToPM(pos), 0);
}

Item* ItemManager::getRandomItem()
{
    Item* item = m_ListItem[rand() % (m_ListItem.size()-1)];
    if (item->isActive())
    {
        for (auto it : m_ListItem)
        {
            if (it->isBorn() == false&&it->isActive()==false) return it;
        }
        return nullptr;
    }
    return item;
}

Item* ItemManager::CreateItem(ITEM type)
{
    Item* item = nullptr;
    switch (type)
    {
    case ITEM_AllowThrowBomb:
        item = new ItemAllowThrowBomb();
        break;
    case ITEM_CoolDownThrowBomb:
        item = new ItemCoolDownThrowBomb();
        break;
    case ITEM_CoolDownThrowBullet:
        item = new ItemCoolDownThrowBullet();
        break;
    case ITEM_CoolDownTimeBomb:
        item = new ItemCoolDownTimeBomb();
        break;
    case ITEM_DamgeBomb:
        item = new ItemDamgeBomb();
        break;
    case ITEM_DamgeBullet:
        item = new ItemDamgeBullet();
        break;
    case ITEM_Heart:
        item = new ItemHeart();
        break;
    case ITEM_Jump:
        item = new ItemJump();
        break;
    case ITEM_PowerThrowBomb:
        item = new ItemPowerThrowBomb();
        break;
    case ITEM_PowerThrowBullet:
        item = new ItemPowerThrowBullet();
        break;
    case ITEM_Speed:
        item = new ItemSpeed();
        break;
    default:
        break;
    }
    if (item != nullptr)
    {
        item->Init();
    }
    return item;
}

void ItemManager::Reset()
{
    for (auto it : m_ListItem)
    {
        if (it != nullptr)
        {
            it->Reset();
        }
    }
}
