#pragma once
#include "../GameManager/ResourceManager.h"
#include "WaterReflect.h"
#include "Cloud.h"
#include "ParallexCloud.h"
#include "BackTree.h"


#include <list>

class BackGround:public CSingleton<BackGround>
{
public:
	BackGround();
	~BackGround();
	void Init();
	void Draw(sf::RenderWindow *window);
	void Update(float deltaTime);
	void setAllowDrawTree(bool isAllowDrawTree);
private:
	sf::RectangleShape m_Layer0;
	std::list< WaterReflect*> m_Layer1;
	std::list<Cloud*> m_Layer2;
	ParallexCloud* m_Layer3;
	std::list<BackTree*> m_Layer4;
	bool m_AllowDrawTree;

	
};