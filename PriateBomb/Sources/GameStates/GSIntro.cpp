#include "GSIntro.h"

GSIntro::GSIntro()
{
	m_NeedChangeNextState = false;
}

GSIntro::~GSIntro()
{
	
}

void GSIntro::Exit()
{
	
}

void GSIntro::Pause()
{
	m_CurrentTime = 0.f;
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
	m_CurrentTime = 0.f;
	GameButton::setWindow(Window);

	m_BackGround.setTexture(*ResourceManagers::GetInstance()->GetTexture("LapTrinhTuTraiTim"));
	m_BackGround.setPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround.scale(0.9f, 0.9f);
	m_BackGround.setOrigin((sf::Vector2f)m_BackGround.getTexture()->getSize() * 0.5f);
	m_Shadow.Init();
	m_BackGround.move(0,20);


	m_Logo.setTexture(ResourceManagers::GetInstance()->GetTexture("Logo"));
	m_Logo.setSize((sf::Vector2f)m_Logo.getTexture()->getSize());
	m_Logo.setPosition(screenWidth / 2, screenHeight / 2);
	m_Logo.setOrigin(m_Logo.getSize() * 0.5f);
	m_ColorLogo = m_Logo.getFillColor();
	m_ColorLogo.a = 0;
	m_Logo.setFillColor(m_ColorLogo);
	m_uplogo = false;
	//m_Logo.move(0, 200);

	m_Meo.setTexture(ResourceManagers::GetInstance()->GetTexture("cute-kitten6"));
	m_Meo.setSize((sf::Vector2f)m_Meo.getTexture()->getSize());
	m_Meo.setPosition(screenWidth / 2, screenHeight / 2);
	m_Meo.setOrigin(m_Meo.getSize() * 0.5f);
	m_ColorMeo = m_Meo.getFillColor();
	m_ColorMeo.a = 0;
	m_Meo.setFillColor(m_ColorMeo);

	m_Layer.setFillColor(sf::Color::Black);
	m_Layer.setDir(true);
}
void GSIntro::Update(const float& dt)
{
	//GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
	if (m_Shadow.isEnd())
	{
		m_Shadow.setColor(sf::Color::White);
		m_uplogo = true;
	}
	m_Shadow.Update(dt);
	if (m_uplogo == true)
	{
		if(m_ColorLogo.a<250) m_ColorLogo.a++;
		m_ColorMeo.a = m_ColorLogo.a;
		m_Logo.setFillColor(m_ColorLogo);
		m_Meo.setFillColor(m_ColorMeo);
		if (m_ColorLogo.a == 250)
		{
			m_CurrentTime += dt;
			
			if (m_CurrentTime > 1.f)
			{
				m_Layer.Update(dt);
				if (m_Layer.isEnd())
				{
					LoadingAllDate();
					GameStateMachine::GetInstance()->ChangeState(STATE_Menu);
				}
			}
		}
	}
}

void GSIntro::Render()
{
	Window->clear(sf::Color(255, 255, 255));
	Window->draw(m_BackGround);
	m_Shadow.Draw(Window);
	Window->draw(m_Meo);
	Window->draw(m_Logo);
	Window->draw(m_Layer);
}

void GSIntro::LoadingAllDate()
{
	ResourceManagers::GetInstance()->AddTexture("BackPalmTreeLeft");
	ResourceManagers::GetInstance()->AddTexture("BackPalmTreeRegular");
	ResourceManagers::GetInstance()->AddTexture("BackPalmTreeRight");
	ResourceManagers::GetInstance()->AddTexture("BatFlying");
	ResourceManagers::GetInstance()->AddTexture("BatHit");
	ResourceManagers::GetInstance()->AddTexture("BG Image");
	ResourceManagers::GetInstance()->AddTexture("Big Clouds");
	ResourceManagers::GetInstance()->AddTexture("black-kitten6");
	ResourceManagers::GetInstance()->AddTexture("Bomb");
	ResourceManagers::GetInstance()->AddTexture("BulletExplosion");
	ResourceManagers::GetInstance()->AddTexture("BBulletFire");
	ResourceManagers::GetInstance()->AddTexture("cute-kitten6");
	ResourceManagers::GetInstance()->AddTexture("LapTrinhTuTraiTim");
	ResourceManagers::GetInstance()->AddTexture("Logo");
	ResourceManagers::GetInstance()->AddTexture("particles");
	ResourceManagers::GetInstance()->AddTexture("Player-Bomb-Guy");
	ResourceManagers::GetInstance()->AddTexture("rpg");
	ResourceManagers::GetInstance()->AddTexture("Small Cloud 1");
	ResourceManagers::GetInstance()->AddTexture("Small Cloud 2");
	ResourceManagers::GetInstance()->AddTexture("Small Cloud 3");
	ResourceManagers::GetInstance()->AddTexture("WaterReflectBig");
	ResourceManagers::GetInstance()->AddTexture("WaterReflectMedium");
	ResourceManagers::GetInstance()->AddTexture("WaterReflectSmall");

	ResourceManagers::GetInstance()->AddFrameData("BackPalmTreeLeft");
	ResourceManagers::GetInstance()->AddFrameData("BackPalmTreeRegular");
	ResourceManagers::GetInstance()->AddFrameData("BackPalmTreeRight");
	ResourceManagers::GetInstance()->AddFrameData("BatFlying");
	ResourceManagers::GetInstance()->AddFrameData("BatHit");
	ResourceManagers::GetInstance()->AddFrameData("Bomb");
	ResourceManagers::GetInstance()->AddFrameData("BulletExplosion");
	ResourceManagers::GetInstance()->AddFrameData("BulletFire");
	ResourceManagers::GetInstance()->AddFrameData("particles");
	ResourceManagers::GetInstance()->AddFrameData("Player-Bomb-Guy");
	ResourceManagers::GetInstance()->AddFrameData("WaterReflectBig");
	ResourceManagers::GetInstance()->AddFrameData("WaterReflectMedium");
	ResourceManagers::GetInstance()->AddFrameData("WaterReflectSmall");

}
