#include "BombManager.h"
#include "../GameStates/GameStateBase.h"

BombManager::BombManager()
{
    m_Num = 30;
    m_Pos = b2Vec2_zero;
    m_Damge = 0.f;
    m_Power = 30.f;
    m_CurrentTime = 0.f;
    m_TimeSkill = 0.2f;
    m_isFire = false;
    m_AllowThrow = false;

}

BombManager::~BombManager()
{
    if (m_MouseDirect != nullptr)
    {
        delete m_MouseDirect;
    }
    m_MouseDirect = nullptr;

    for (auto it : m_BombList)
    {
        if (it != nullptr)
        {
            delete it;
        }
        it = nullptr;
    }
    m_BombList.clear();
}

void BombManager::setPostion(b2Vec2 pos)
{
    m_Pos = pos;
    m_MouseDirect->setPointA(World::ConvertToPixal(pos));
}

void BombManager::Init()
{
    m_MouseDirect = new MouseDirect();
    for (int i = 0; i < m_Num; i++)
    {
        Bomb* tmp = new Bomb();
        tmp->Init();
        tmp->setDamge(m_Damge);
        m_BombList.push_back(tmp);
    }
}

void BombManager::Update(float deltaTime)
{
    m_MouseDirect->Update(deltaTime, sf::Mouse::getPosition(*GameStateBase::Window));
    if (m_isFire == true)
    {
        m_CurrentTime += deltaTime;
        if (m_CurrentTime >= m_TimeSkill)
        {
            m_CurrentTime = 0.f;
            m_isFire = false;
        }
    }
    for (auto it : m_BombList)
    {
        if (it->isActive())
        {
            it->Update(deltaTime);
        }
    }
    
}

void BombManager::Draw(sf::RenderWindow *window)
{
    for (auto it : m_BombList)
    {
        if (it->isActive()) 
               it->Draw(window);
    }
}

void BombManager::Fire()
{
    if (m_isFire == true) return;
    for (auto it : m_BombList)
    {
        if (!it->isActive())
        {
            it->setActive(true);
            it->setNextState(IBomb::STATE_BOMBOFF);
            it->GetBody()->SetTransform(m_Pos, 0.f);
            it->getBody()->SetLinearVelocity(b2Vec2(0, 0));
            if (m_AllowThrow)
            {
                b2Vec2 blase = m_MouseDirect->getVectorUnit();
                blase *= m_Power;
                it->GetBody()->ApplyLinearImpulseToCenter(blase, true);
            }
            m_isFire = true;
            break;
        }
    }
}

Bomb* BombManager::getBomb()
{
    for (auto it : m_BombList)
    {
        if (!it->isActive())
        {
            return it;
            break;
        }
    }
    return nullptr;
}

void BombManager::setTimeSkill(float timeSkill)
{
    m_TimeSkill = timeSkill;
}

void BombManager::setDamge(float Damge)
{
    m_Damge = Damge;
    for (auto it : m_BombList)
    {
        if (it != nullptr)
        {
            it->setDamge(Damge);
        }
    }
}

void BombManager::AllowThrow(bool allow)
{
    m_AllowThrow = allow;
}

void BombManager::setSpeed(float power)
{
    m_Power = power;
}

void BombManager::setCoolDownTime(float time)
{
    m_CoolDownTime = time;
    for (auto it : m_BombList)
    {
        if (it != nullptr)
        {
            it->setCoolDownTime(time);
        }
    }

}
