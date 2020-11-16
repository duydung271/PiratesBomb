#include "Player.h"
#include "IdlePState.h"
#include "RunPState.h"
#include "JumpState.h"
#include "FallState.h"
#include "JumpAnticipation.h"
#include "GroundState.h"
#include "HitState.h"
#include "DeadGroundState.h"
#include "DeadHitState.h"

#include "../GameStates/GameStateBase.h"

Player::Player()
{
    m_CurrentAction = IPState::Idle;
    m_IdleState = new IdlePState(this);
    m_RunState = new RunPState(this);
    m_JumpState = new JumpPState(this);
    m_FallState = new FallPState(this);
    m_JumpAnticipationState = new JumpAnticipationPState(this);
    m_GroundState = new GroundPState(this);
    m_HitState = new HitState(this);
    m_DeadGroundState = new DeadGroundState(this);
    m_DeadHitState = new DeadHitState(this);

    m_CurrentState = m_IdleState;
    m_NextAction = IPState::STATE_NULL;

}

Player::~Player()
{
    if (m_IdleState != nullptr)
    {
        delete m_IdleState;
    }
    m_IdleState = nullptr;

    if (m_JumpState != nullptr)
    {
        delete m_JumpState;
    }
    m_JumpState = nullptr;

    if (m_RunState != nullptr)
    {
        delete m_RunState;
    }
    m_RunState = nullptr;

    if (m_FallState != nullptr)
    {
        delete m_FallState;
    }
    m_FallState = nullptr;

    if (m_JumpAnticipationState != nullptr)
    {
        delete m_JumpAnticipationState;
    }
    m_JumpAnticipationState = nullptr;

    if (m_GroundState != nullptr)
    {
        delete m_GroundState;
    }
    m_GroundState = nullptr;

    if (m_HitState != nullptr)
    {
        delete m_HitState;
    }
    m_HitState = nullptr;

    if (m_DeadHitState != nullptr)
    {
        delete m_DeadHitState;
    }
    m_DeadHitState = nullptr;

    if (m_DeadGroundState != nullptr)
    {
        delete m_DeadGroundState;
    }
    m_DeadGroundState = nullptr;

    m_CurrentState = nullptr;

    if (m_Animation != nullptr)
    {
        delete m_Animation;
    }
    m_Animation = nullptr;

    if (m_HitBox != nullptr)
    {
        delete m_HitBox;
    }
    m_HitBox = nullptr;

    if (m_Attribute != nullptr)
    {
        delete m_Attribute;
    }
    m_Attribute = nullptr;

    if (m_BombManager != nullptr)
    {
        delete m_BombManager;
    }
    m_BombManager = nullptr;

    if (m_Rocket != nullptr)
    {
        delete m_Rocket;
    }
    m_Rocket = nullptr;

    if (m_HeartBar != nullptr)
    {
        delete m_HeartBar;
    }
    m_HeartBar = nullptr;
}

void Player::SetAction()
{
    if (m_NextAction == IPState::STATE_NULL) return;
    m_Animation->Reset();
    m_CurrentAction = m_NextAction;
    switch (m_NextAction)
    {
    case IPState::Idle:
        m_CurrentState = m_IdleState;
        break;
    case IPState::Run:
        m_CurrentState = m_RunState;
        break;
    case IPState::Jump:
        m_CurrentState = m_JumpState;
        break;
    case IPState::Fall:
        m_CurrentState = m_FallState;
        break;
    case IPState::JumpAnticipation:
        m_CurrentState = m_JumpAnticipationState;
        break;
    case IPState::DeadGroundState:
        m_CurrentState = m_DeadGroundState;
        break;
    case IPState::DeadHit:
        m_CurrentState = m_DeadHitState;
        break;
    case IPState::Hit:
        m_CurrentState = m_HitState;
        break;
    case IPState::Ground:
        m_CurrentState = m_GroundState;
        break;
    default:
        break;
    }
    m_Animation->setState(m_CurrentAction);
    m_NextAction = IPState::STATE_NULL;
}

void Player::SetState(IPState* newState)
{
    m_CurrentState = newState;
}

void Player::Init()
{
   

    m_Animation = new AnimationComponent();
    m_Animation->Init("Player-Bomb-Guy");
    m_Animation->setPosition(200.f, 200.f);
    float radius = 20.f;
    m_HitBox = new HitCircleComponent((sf::Vector2f)m_Animation->getPosition(), radius);

    m_IdleState->Init();
    m_RunState->Init();
    m_JumpState->Init();
    m_FallState->Init();
    m_JumpAnticipationState->Init();
    m_GroundState->Init();
    m_HitState->Init();
    //Set thuoc tinh cho nhan vat
    m_Attribute = new AttributeComponent();
    m_Attribute->setAllowThrowBomb(false);
    m_Attribute->setMaxHP(200);
    m_Attribute->setHP(200);
    m_Attribute->setVelocity(sf::Vector2f(100.f, 400.f));
    m_Attribute->setDamegeBullet(10.f);
    m_Attribute->setDamgeBomb(100.f);
    m_Attribute->setTimeThrowBomb(1.f);
    m_Attribute->setTimeThrowBullet(0.3f);
    m_Attribute->setCoolDownBomb(5.f);
    m_Attribute->setPowerThrowBomb(20.f);
    m_Attribute->setPowerThrowBullet(0.3f);// Weigh Bullet <<< nho hon nhieu so voi Bomb
    //Mode tool on
    GetBody()->SetUserData(m_Attribute);

    m_BombManager = new BombManager();
    m_BombManager->setDamge(m_Attribute->getDamgeBomb());
    m_BombManager->Init();
    m_BombManager->setTimeSkill(m_Attribute->getTimeThrowBomb());

    m_Rocket = new Rocket();
    m_Rocket->setDamge(m_Attribute->getDamgeBullet());
    m_Rocket->Init();

    m_HeartBar = new HeartBar();
    m_HeartBar->setAttribute(m_Attribute);
    m_HeartBar->setEntity(m_HitBox);
    m_HeartBar->Init();
    m_HeartBar->setOffSet(sf::Vector2f(0.f, -30.f));
    m_HeartBar->setSize(sf::Vector2f(50.f, 5.f));
    m_CountTimeTakeDam = 0.f;

    ApplyAttributeDate();
}

void Player::Draw(sf::RenderWindow* window)
{
    window->draw(*m_Animation);
    //window->draw(*m_HitBox);
    m_CurrentState->Draw(window);
    m_BombManager->Draw(window);  
    m_Rocket->Draw(window);
    if (m_CurrentWeapon == WEAPON_ROCKET)
    {
        window->draw(*m_Rocket);
    }
    m_HeartBar->Draw(window);
 
}

void Player::Update(float deltaTime)
{
    SetAction();
    ApplyAttributeDate();
    CollisionDamge(deltaTime);
    if (m_Attribute->isDead()) m_HitBox->Body->SetActive(false);
    if (!m_Attribute->isDead()) WeaponUpdate(deltaTime);
    m_CurrentState->Update(deltaTime);
    m_HitBox->Update(deltaTime);

    m_Animation->Update(deltaTime);
    m_Animation->setPosition(m_HitBox->getPosition().x, (m_HitBox->getPosition().y-10.f));
    m_Attribute->Update(deltaTime);
 
    m_HeartBar->Update(deltaTime);

}

IPState* Player::GetState()
{
    return m_CurrentState;
}


void Player::SetNextAction(IPState::STATE nextAction)
{
    m_NextAction = nextAction;
}

void Player::WeaponUpdate(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        m_CurrentWeapon = WEAPON_BOMB;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        m_CurrentWeapon = WEAPON_ROCKET;
    }

    if (m_CurrentWeapon == WEAPON_BOMB)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_BombManager->setPostion(GetBody()->GetPosition());
            m_BombManager->Fire();
        }
    }
    else
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_Rocket->setPostion(GetBody()->GetPosition());
            m_Rocket->Fire();
        }
        m_Rocket->setPosition(this->GetAnimation()->getPosition());
    }
    m_BombManager->Update(deltaTime);
    m_Rocket->Update(deltaTime);

}

void Player::CollisionDamge(float deltaTime)
{
    int dam = 0;
    AttributeComponent* data = nullptr;
    for (b2ContactEdge* edge = GetBody()->GetContactList(); edge; edge = edge->next)
    {
       
        if (edge->contact->GetFixtureB()->GetFilterData().categoryBits & CATEGORY_MONSTER)
        {
            data = (AttributeComponent*)edge->contact->GetFixtureB()->GetBody()->GetUserData();
        }else
        if (edge->contact->GetFixtureB()->GetFilterData().categoryBits & CATEGORY_BULLET_BOSS)
        {
            data = (AttributeComponent*)edge->contact->GetFixtureB()->GetBody()->GetUserData();
        }else
        if (edge->contact->GetFixtureB()->GetFilterData().categoryBits & CATEGORY_BOSS)
        {
            data = (AttributeComponent*)edge->contact->GetFixtureB()->GetBody()->GetUserData();
        }
        if (data != nullptr)
        {
            dam = data->getDamge();
            m_Attribute->setIsPush(true);
        }
        if (dam != 0) break;
    }

    if (m_CountTimeTakeDam != 0.f)
    {
        m_CountTimeTakeDam += deltaTime;
        if (m_CountTimeTakeDam < 0.5f) return;
        m_CountTimeTakeDam = 0.f;
    }
    if (dam != 0&&m_CountTimeTakeDam==0.f)
    {
        m_CountTimeTakeDam += deltaTime;
        m_Attribute->LoseHP(dam);
    }
}

void Player::ApplyAttributeDate()
{
    m_BombManager->setTimeSkill(m_Attribute->getTimeThrowBomb());
    m_BombManager->setDamge(m_Attribute->getDamgeBomb());
    m_BombManager->AllowThrow(m_Attribute->isAllowThrowBomb());
    m_BombManager->setSpeed(m_Attribute->getSpeedBomb());
    m_BombManager->setCoolDownTime(m_Attribute->getCoolTimeBomb());

    m_Rocket->setTimeSkill(m_Attribute->getTimeThrowBullet());
    m_Rocket->setDamge(m_Attribute->getDamgeBullet());
    m_Rocket->setSpeed(m_Attribute->getSpeedBullet());
}
