#pragma once
#include "GameStates/GameStateMachine.h"
#include "GameStates/GameStateBase.h"

class Application : public CSingleton<Application>
{
public:
	Application();
	virtual ~Application();
	void		Init();
	void		Run();
	void		Exit();
	void		Render();
	//Update
	void UpdateDt();
	void UpdateSFMLEvents();
	void Update();
	//Get
	
private:
	sf::RenderWindow *m_Window;
	sf::Event *m_Event;
	sf::Clock m_DtClock;
	float m_DeltaTime;
	int numState = 1;
};