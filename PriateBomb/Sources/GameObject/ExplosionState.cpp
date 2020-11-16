#include "ExplosionState.h"

ExpolsionState::~ExpolsionState()
{
	if (m_ExplosionEffect!=nullptr)
	{
		delete m_ExplosionEffect;
	}
	m_ExplosionEffect = nullptr;
}

void ExpolsionState::Init()
{
	m_ExplosionEffect = new ExplosionEffect(m_Bomb->GetBody());
	m_ExplosionEffect->setBlastPower(1000);
	m_ExplosionEffect->setBlastRadius(6);
}

void ExpolsionState::Update(const float deltaTime)
{
	m_Bomb->GetBody()->SetTransform(m_Bomb->GetBody()->GetPosition(), 0.f);
	if (m_CurrentTime == 0.f)
	{
		m_ExplosionEffect->explode_proximity();
		m_Bomb->GetBody()->SetActive(false);
		m_Bomb->GetBody()->SetAwake(false);	
		m_Bomb->GetAnimation()->setScale(3, 3);
	}
	m_CurrentTime += deltaTime;
	if (m_Bomb->GetAnimation()->isEndFrame())
	{
		m_Bomb->GetAnimation()->setScale(1, 1);
		m_Bomb->setNextState(IBomb::STATE_STOP);
		m_CurrentTime = 0.f;
	}
}

void ExpolsionState::Draw(sf::RenderWindow* window)
{
}
