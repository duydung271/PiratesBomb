#include "GroundState.h"

GroundPState::GroundPState(IPlayer* player)
{
	m_Player = player;
	m_isGround = false;
	m_Animation = new AnimationComponent();
	m_Animation->Init("particles");
	m_Animation->setState(ParticlesSTATE::STATE_FALL);
}

GroundPState::~GroundPState()
{
	if (m_Animation != nullptr)
	{
		delete m_Animation;
	}
	m_Animation = nullptr;
}

void GroundPState::Init()
{
}

void GroundPState::Draw(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void GroundPState::Update(float deltaTime)
{
	if (m_isGround == false)
	{
		m_isGround = true;
		m_isEnd = false;
		sf::Vector2f pos = m_Player->GetAnimation()->getPosition();
		pos.y += 10.f;
		m_Animation->setPosition(pos);
		m_Animation->setDirect(m_Player->GetAnimation()->getDirect());
	}


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

	if (m_Player->GetAnimation()->isEndFrame())
	{
		m_Player->GetAnimation()->Reset();
		m_Player->SetNextAction(IPState::Idle);
		m_isGround = false;
		m_isEnd = false;
		m_Animation->Reset();
	}
	if (m_Player->GetAttribute()->isHit()) m_Player->SetNextAction(IPState::Hit);
	if (m_Player->GetAttribute()->isDead()) m_Player->SetNextAction(IPState::DeadHit);
}
