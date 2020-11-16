#include "GSMenu.h"
StateTypes GSMenu::m_nextState = STATE_INVALID;
GSMenu::GSMenu()
{
	m_currentTime = 0.0f;
}

GSMenu::~GSMenu()
{
	if (m_BackGround != nullptr)
	{
		delete m_BackGround;
	}
	m_BackGround = nullptr;
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
	BackGround::GetInstance()->setAllowDrawTree(false);
}

void GSMenu::Init()
{
	m_BackGround = new sf::RectangleShape();
	m_BackGround->setTexture(ResourceManagers::GetInstance()->GetTexture("background1"));
	m_BackGround->setSize((sf::Vector2f)Window->getSize());

	auto button = new GameButton("Button\\play");
	button->SetOnClick([]() {
		m_nextState = STATE_Play;
		});
	button->setPosition(screenWidth/2,screenHeight/2+200);
	button->setSize(sf::Vector2f(200, 200));
	button->setOrigin(button->getSize() * 0.5f);
	m_ButtonList.push_back(button);

	button = new GameButton("Button//close");
	button->SetOnClick([]() {
		Window->close();
		});
	button->setPosition(screenWidth / 2+300, screenHeight / 2+400);
	button->setSize(sf::Vector2f(100, 100));
	button->setOrigin(button->getSize() * 0.5f);
	m_ButtonList.push_back(button);

	button = new GameButton("Button//faq");
	button->SetOnClick([]() {
		});
	button->setPosition(screenWidth / 2 +100, screenHeight / 2 + 400);
	button->setSize(sf::Vector2f(100, 100));
	button->setOrigin(button->getSize() * 0.5f);
	m_ButtonList.push_back(button);

	button = new GameButton("Button//prize");
	button->SetOnClick([]() {
		});
	button->setPosition(screenWidth / 2-100, screenHeight / 2 + 400);
	button->setSize(sf::Vector2f(100, 100));
	button->setOrigin(button->getSize() * 0.5f);
	m_ButtonList.push_back(button);

	button = new GameButton("Button//settings");
	button->SetOnClick([]() {
		});
	button->setPosition(screenWidth / 2-300, screenHeight / 2 + 400);
	button->setSize(sf::Vector2f(100, 100));
	button->setOrigin(button->getSize() * 0.5f);
	m_ButtonList.push_back(button);

	BackGround::GetInstance()->setAllowDrawTree(false);
	m_Boss = new AnimationComponent();
	m_Boss->Init("DemonRun");
	m_Boss->setScale(4.f, 4.f);
	m_Boss->setPosition(screenWidth / 2 + 50, screenHeight / 2 - 300);
	m_Text.setString("Pirate Bomb");
	m_Text.setFont(*ResourceManagers::GetInstance()->GetFont("Planes_ValMore"));
	m_Text.setOutlineColor(sf::Color::Black);
	m_Text.setOutlineThickness(1.f);
	m_Text.setPosition(screenWidth / 2-290, screenHeight / 2-50);
	m_Text.setCharacterSize(100.f);

	
	m_Layer.setFillColor(sf::Color::Black);
	m_Layer.setDir(false);
	m_LayerOut.setFillColor(sf::Color::Black);
	m_LayerOut.setDir(true);
}

void GSMenu::Update(const float& dt)
{
	//GameStateMachine::GetInstance()->ChangeState(STATE_Play);
	m_Text.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	if (m_nextState != STATE_INVALID)
	{
		m_LayerOut.Update(dt);
		if (m_LayerOut.isEnd())
		{
			GameStateMachine::GetInstance()->ChangeState(m_nextState);
			GameStateMachine::GetInstance()->NextState()->Init();
			m_nextState = STATE_INVALID;
			m_Layer.setFillColor(sf::Color::Black);
			m_Layer.setDir(false);
			m_LayerOut.setFillColor(sf::Color::Black);
			m_LayerOut.setDir(true);
			m_currentTime = 0.f;
		}
	}
	BackGround::GetInstance()->Update(dt);
	m_Layer.Update(dt);
	m_Boss->Update(dt);
	for (auto it : m_ButtonList)
	{
		it->Update(dt);
	}
}

void GSMenu::Render()
{
	Window->draw(*m_BackGround);
	BackGround::GetInstance()->Draw(Window);
	Window->draw(*m_Boss);
	for (auto it : m_ButtonList)
	{
		Window->draw(*it);
	}
	Window->draw(m_Text);
	Window->draw(m_Layer);
	Window->draw(m_LayerOut);
	
}

