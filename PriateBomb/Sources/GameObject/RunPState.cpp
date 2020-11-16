#include "RunPState.h"

RunPState::RunPState(IPlayer* player)
{
	m_Player = player;
	m_Animation = new AnimationComponent();
	m_Animation->Init("particles");
	m_Animation->setState(ParticlesSTATE::STATE_RUN);
}

RunPState::~RunPState()
{
	if (m_Animation != nullptr)
	{
		delete m_Animation;
	}
	m_Animation = nullptr;
}

void RunPState::Init()
{
	
}

void RunPState::Draw(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void RunPState::Update(float deltaTime)
{
	sf::Vector2f velocity(m_Player->GetBody()->GetLinearVelocity().x, m_Player->GetBody()->GetLinearVelocity().y);
	velocity = velocity * SCALE;
	sf::Vector2f pos = m_Player->GetAnimation()->getPosition();
	pos.y += 15.f;
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = m_Player->GetAttribute()->getVelocity().x;
		m_Player->GetAnimation()->setDirect(DIRECT::DIRECT_RIGHT);
		pos.x -= 15.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = -m_Player->GetAttribute()->getVelocity().x;
		m_Player->GetAnimation()->setDirect(DIRECT::DIRECT_LEFT);
		pos.x += 15.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_Player->SetNextAction(IPState::Jump);
	}

	m_Player->GetBody()->SetLinearVelocity(World::ConvertToPM(velocity));
	m_Animation->setPosition(pos);
	m_Animation->setDirect(m_Player->GetAnimation()->getDirect());

	m_Animation->Update(deltaTime);
	if (m_Player->GetBody()->GetLinearVelocity() == b2Vec2(0.f, 0.f))
	{
		m_Player->SetNextAction(Idle);
		m_Animation->Reset();
	}
	if (m_Player->GetAttribute()->isHit()) m_Player->SetNextAction(IPState::Hit);
	if (m_Player->GetAttribute()->isDead()) m_Player->SetNextAction(IPState::DeadHit);
}
