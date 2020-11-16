#include "GSGameplay.h"

GSGameplay::GSGameplay()
{
	b2Vec2 gravity(0.f, 9.81f + 7.f);
	m_World = new b2World(gravity);
	World::GetInstance()->setWorld(m_World);
	m_currentTime = 0.f;
	m_wasInit = false;

}

GSGameplay::~GSGameplay()
{
	if (m_TileMap != nullptr)
	{
		delete m_TileMap;
	}
	m_TileMap= nullptr;
	if (m_Player != nullptr)
	{
		delete m_Player;
	}
	m_Player = nullptr;
	if (m_LevelManger != nullptr)
	{
		delete m_LevelManger;
	}
	m_LevelManger = nullptr;
}

void GSGameplay::Exit()
{
}

void GSGameplay::Pause()
{
}

void GSGameplay::Resume()
{
	BackGround::GetInstance()->setAllowDrawTree(true);
}

void GSGameplay::Init()
{
	if (m_wasInit == true) return;

	m_wasInit = true;
	m_TileMap = new TileMap();
	m_TileMap->Load("Map.json");

	m_Player = new Player();
	m_Player->Init();
	
	m_LevelManger = new LevelManager();
	m_LevelManger->Init(m_Player);

	m_LayerLight.setFillColor(sf::Color::Black);
	m_LayerLight.setDir(true);
	m_LayerLight.setAlphaMax(230);

	m_LayerTop.setFillColor(sf::Color::Black);
	m_LayerTop.setDir(true);


	BackGround::GetInstance()->setAllowDrawTree(true);
	m_LayerIntro.setFillColor(sf::Color(0, 0, 0));
	m_LayerIntro.setDir(false);

	ItemManager::GetInstance()->Init();
	m_ModeTool = false;

}

void GSGameplay::Update(const float& dt)
{
	//GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_End);
	m_LayerIntro.Update(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) ItemManager::GetInstance()->BornItem();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) m_ModeTool = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) m_ModeTool = true;
	if (m_ModeTool) m_Player->GetAttribute()->setHP(200);
	if (m_Player->GetAttribute()->isDead())
	{
		m_currentTime += dt;
		m_LayerTop.Update(dt);
		if (m_currentTime > 3.f)
		{
			GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_End);
			m_currentTime = 0.f;
		}
	}
	if (m_LevelManger->getLevel()==LevelManager::LEVEL_4) m_LayerLight.Update(dt);


	m_World->Step(1.f / 60.f, 24, 12);
	BackGround::GetInstance()->Update(dt);

	m_LevelManger->Update(dt);
	m_Player->Update(dt);
	ItemManager::GetInstance()->Update(dt);
}

void GSGameplay::Render()
{
	BackGround::GetInstance()->Draw(Window);
	
	Window->draw(*m_TileMap);
	Window->draw(m_LayerLight);
	m_Player->Draw(Window);
	m_LevelManger->Draw(Window);
	ItemManager::GetInstance()->Draw(Window);
	Window->draw(m_LayerTop);
	Window->draw(m_LayerIntro);

}
