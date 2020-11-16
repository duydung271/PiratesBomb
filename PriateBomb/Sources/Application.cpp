#include "Application.h"

Application::Application()
{
	m_Window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), TileGame, sf::Style::Fullscreen);
	m_Window->setVerticalSyncEnabled(false);
	m_Window->setFramerateLimit(120);
	GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Intro);
	m_Event = new sf::Event();
	GameStateBase::setWindow(m_Window);
	//printf("%d %d\n",m_Window->getSize().x, m_Window->getSize().y);
}


Application::~Application()
{
	m_Window = nullptr;
	m_Event = nullptr;
}


void Application::Init()
{
	
}

void Application::Run()
{
	while (m_Window->isOpen())
	{
		UpdateDt();
		Update();
		Render();	
	}
}

void Application::Render()
{
	m_Window->clear();
	if (GameStateMachine::GetInstance()->HasState())
		GameStateMachine::GetInstance()->CurrentState()->Render();
	m_Window->display();

}


void Application::Exit()
{
	m_Window->close();
	std::cout << "Application is Exit!\n";
}

void Application::UpdateDt()
{
	/*Updates the dt variable with the time it takes to update and render one frame.*/
	m_DeltaTime = m_DtClock.restart().asSeconds();
}

void Application::UpdateSFMLEvents()
{
	while (m_Window->pollEvent(*m_Event))
	{
		switch (m_Event->type)
		{
		case sf::Event::Closed:
			Exit();
			break;
		default:
			break;
		}
	}
}

void Application::Update()
{
	GameStateMachine::GetInstance()->PerformStateChange();
	if (GameStateMachine::GetInstance()->HasState())
		GameStateMachine::GetInstance()->CurrentState()->Update(m_DeltaTime);
	UpdateSFMLEvents();
}
