#include "JumpState.h"

JumpPState::JumpPState(IPlayer* player)
{
	m_Player = player;
	m_isJump = false;
	m_Animation = new AnimationComponent();
	m_Animation->Init("particles");
	m_Animation->setState(ParticlesSTATE::STATE_JUMP);
}

JumpPState::~JumpPState()
{
	if (m_Animation != nullptr)
	{
		delete m_Animation;
	}
	m_Animation = nullptr;
}

void JumpPState::Init()
{

}

void JumpPState::Draw(sf::RenderWindow* window)
{
	if (m_isEnd==false) window->draw(*m_Animation);
}

void JumpPState::Update(float deltaTime)
{
	sf::Vector2f velocity(m_Player->GetBody()->GetLinearVelocity().x, m_Player->GetBody()->GetLinearVelocity().y);
	velocity = velocity * SCALE;
	if (m_isJump == false)
	{
		velocity.y = -m_Player->GetAttribute()->getVelocity().y;
		m_isJump = true;
		m_isEnd = false;
		sf::Vector2f pos = m_Player->GetAnimation()->getPosition();
		pos.y += 10.f;
		m_Animation->setPosition(pos);
		m_Animation->setDirect(m_Player->GetAnimation()->getDirect());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = m_Player->GetAttribute()->getVelocity().x;
		m_Player->GetAnimation()->setDirect(DIRECT::DIRECT_RIGHT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = -m_Player->GetAttribute()->getVelocity().x;
		m_Player->GetAnimation()->setDirect(DIRECT::DIRECT_LEFT);
	}

	m_Player->GetBody()->SetLinearVelocity(World::ConvertToPM(velocity));

	if (m_Player->GetAnimation()->isEndFrame())
	{
		m_Player->GetAnimation()->Stop();
	}

	if (m_Animation->isEndFrame())
	{
		m_Animation->Stop();
		m_isEnd = true;
	}
	m_Animation->Update(deltaTime);


	if (m_Player->GetBody()->GetLinearVelocity().y >=0.f)
	{
		m_Player->SetNextAction(IPState::Fall);
		m_isJump = false;
		m_Player->GetAnimation()->Reset();
		m_Animation->Reset();
	}
	if (m_Player->GetAttribute()->isHit()) m_Player->SetNextAction(IPState::Hit);
	if (m_Player->GetAttribute()->isDead()) m_Player->SetNextAction(IPState::DeadHit);
}
