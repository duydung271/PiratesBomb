#include "Rocket.h"



Rocket::Rocket()
{
	m_Num = 100;
	m_Pos = b2Vec2_zero;
	m_Power = 0.5f;
	m_CurrentTime = 0.f;
	m_TimeSkill = 2.f;
	m_isFire = false;
	m_Damge = 0.f;
}

Rocket::~Rocket()
{
	for (auto it : m_BulletList)
	{
		if (it != nullptr)
		{
			delete it;
		}
		it = nullptr;
	}
	m_BulletList.clear();
}

void Rocket::Init()
{
	sf::Texture* texture = ResourceManagers::GetInstance()->GetTexture("rpg");
	this->setSize((sf::Vector2f)texture->getSize());
	this->setTexture(texture);
	this->setOrigin(this->getSize() * 0.5f);
	this->setScale(2.f, 2.f);

	for (int i = 0; i < m_Num; i++)
	{
		Bullet* tmp = new Bullet();
		tmp->Init();
		tmp->setDamge(m_Damge);
		m_BulletList.push_back(tmp);
	}
}

void Rocket::Update(float deltaTime)
{
	m_MouseDirect.setPointA(getPosition());
	m_MouseDirect.Update(deltaTime, sf::Mouse::getPosition(*GameStateBase::Window));
	if (m_MouseDirect.getAngle() < 0.f)
	{
		this->setScale(-2, 2);
	}
	else this->setScale(2, 2);
	this->setRotation(m_MouseDirect.getAngle());

	if (m_isFire == true)
	{
		m_CurrentTime += deltaTime;
		if (m_CurrentTime >= m_TimeSkill)
		{
			m_CurrentTime = 0.f;
			m_isFire = false;
		}
	}

	for (auto it : m_BulletList)
	{
		if (it->isActive())
		{
			it->Update(deltaTime);
		}
	}
}

void Rocket::Draw(sf::RenderWindow* window)
{
	for (auto it : m_BulletList)
	{
		if (it->isActive())
			it->Draw(window);
	}
}

Bullet* Rocket::getBullet()
{
	for (auto it : m_BulletList)
	{
		if (!it->isActive())
		{
			return it;
			break;
		}
	}
	return nullptr;
}

void Rocket::Fire()
{
	if (m_isFire == true) return;

	for (auto it : m_BulletList)
	{
		if (!it->isActive())
		{
			it->setActive(true);
			it->setNextState(IBullet::STATE_FIRE);
			it->getBody()->SetTransform(m_Pos, m_MouseDirect.getAngle()/180*b2_pi);
			it->getBody()->SetFixedRotation(true);
			b2Vec2 blase = m_MouseDirect.getVectorUnit();
			blase *= m_Power;
			it->getBody()->SetLinearVelocity(b2Vec2(0, 0));
			it->getBody()->ApplyLinearImpulseToCenter(blase, false);
			m_isFire = true;
			break;
		}
	}
}

void Rocket::setPostion(b2Vec2 pos)
{
	m_Pos = pos;
	m_MouseDirect.setPointA(World::ConvertToPixal(pos));
}

void Rocket::setTimeSkill(float timeSkill)
{
	m_TimeSkill = timeSkill;
}

void Rocket::setDamge(float Damge)
{
	m_Damge = Damge;
	for (auto it : m_BulletList)
	{
		if (it != nullptr)
		{
			it->setDamge(m_Damge);
		}
	}
}

void Rocket::setSpeed(float power)
{
	m_Power = power;
}
