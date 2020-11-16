#include "BackGround.h"

BackGround::BackGround()
{
	m_Layer0.setSize(sf::Vector2f(screenWidth+30,screenHeight));
	m_AllowDrawTree = true;
	Init();
}

BackGround::~BackGround()
{
	for (auto it : m_Layer1)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
	m_Layer1.clear();

	for (auto it : m_Layer2)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
	m_Layer2.clear();

	if (m_Layer3 != nullptr)
	{
		delete m_Layer3;
	}

	for (auto it : m_Layer4)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
	m_Layer4.clear();
}

void BackGround::Init()
{
	//layer0
	m_Layer0.setTexture(ResourceManagers::GetInstance()->GetTexture("BG Image"));
	m_Layer0.setOrigin(m_Layer0.getSize() * 0.5f);
	m_Layer0.setScale(1.f,1.2f);
	sf::Vector2f pos = m_Layer0.getSize() * 0.5f;
	pos.y += 100.f;
	m_Layer0.setPosition(pos);
	//layer1
	auto waterReflect= new WaterReflect();
	waterReflect->Init("WaterReflectBig");
	waterReflect->setPositison(sf::Vector2f(screenWidth/2, screenHeight-180.f));
	m_Layer1.push_back(waterReflect);

	waterReflect = new WaterReflect();
	waterReflect->Init("WaterReflectBig");
	waterReflect->setPositison(sf::Vector2f(screenWidth / 2 - 600.f, screenHeight - 180.f));
	m_Layer1.push_back(waterReflect);

	waterReflect = new WaterReflect();
	waterReflect->Init("WaterReflectBig");
	waterReflect->setPositison(sf::Vector2f(screenWidth / 2 + 600.f, screenHeight - 180.f));
	m_Layer1.push_back(waterReflect);

	waterReflect = new WaterReflect();
	waterReflect->Init("WaterReflectMedium");
	waterReflect->setPositison(sf::Vector2f(screenWidth / 2 -300.f, screenHeight - 150.f));
	m_Layer1.push_back(waterReflect);

	waterReflect = new WaterReflect();
	waterReflect->Init("WaterReflectMedium");
	waterReflect->setPositison(sf::Vector2f(screenWidth / 2 , screenHeight - 70.f));
	m_Layer1.push_back(waterReflect);

	waterReflect = new WaterReflect();
	waterReflect->Init("WaterReflectSmall");
	waterReflect->setPositison(sf::Vector2f(1200.f, screenHeight - 150.f));
	m_Layer1.push_back(waterReflect);

	waterReflect = new WaterReflect();
	waterReflect->Init("WaterReflectSmall");
	waterReflect->setPositison(sf::Vector2f(200.f, screenHeight - 100.f));
	m_Layer1.push_back(waterReflect);

	waterReflect = new WaterReflect();
	waterReflect->Init("WaterReflectSmall");
	waterReflect->setPositison(sf::Vector2f(screenWidth / 2 + 600.f, screenHeight - 100.f));
	m_Layer1.push_back(waterReflect);

	//layer2
	auto cloud = new Cloud();
	cloud->Init("Small Cloud 3");
	cloud->setPosition(sf::Vector2f(screenWidth, 200.f));
	cloud->setScale(sf::Vector2f(3.f, 3.f));
	m_Layer2.push_back(cloud);

	cloud = new Cloud();
	cloud->Init("Small Cloud 1");
	cloud->setPosition(sf::Vector2f(screenWidth+500, 400.f));
	cloud->setScale(sf::Vector2f(3.f, 3.f));
	cloud->setSpeed(sf::Vector2f(-40.f, 0.f));
	m_Layer2.push_back(cloud);

	cloud = new Cloud();
	cloud->Init("Small Cloud 2");
	cloud->setPosition(sf::Vector2f(screenWidth+1000, 300.f));
	cloud->setScale(sf::Vector2f(3.f, 3.f));
	cloud->setSpeed(sf::Vector2f(-50.f, 0.f));
	m_Layer2.push_back(cloud);

	//layer3
	m_Layer3 = new ParallexCloud();
	m_Layer3->Init();

	//layer4
	//Regular Tree
	auto backTree = new BackTree();
	backTree->Init("BackPalmTreeRegular");
	backTree->setPosition(sf::Vector2f(100, screenHeight-100));
	m_Layer4.push_back(backTree);

	backTree = new BackTree();
	backTree->Init("BackPalmTreeRegular");
	backTree->setPosition(sf::Vector2f(200, screenHeight - 120));
	m_Layer4.push_back(backTree);

	backTree = new BackTree();
	backTree->Init("BackPalmTreeRegular");
	backTree->setPosition(sf::Vector2f(350, screenHeight - 80));
	m_Layer4.push_back(backTree);

	backTree = new BackTree();
	backTree->Init("BackPalmTreeRegular");
	backTree->setPosition(sf::Vector2f(500, screenHeight - 100));
	m_Layer4.push_back(backTree);

	backTree = new BackTree();
	backTree->Init("BackPalmTreeRegular");
	backTree->setPosition(sf::Vector2f(700, screenHeight - 125));
	m_Layer4.push_back(backTree);

	backTree = new BackTree();
	backTree->Init("BackPalmTreeRegular");
	backTree->setPosition(sf::Vector2f(1200, screenHeight - 125));
	m_Layer4.push_back(backTree);

	backTree = new BackTree();
	backTree->Init("BackPalmTreeRegular");
	backTree->setPosition(sf::Vector2f(900, screenHeight - 150));
	m_Layer4.push_back(backTree);

	backTree = new BackTree();
	backTree->Init("BackPalmTreeRegular");
	backTree->setPosition(sf::Vector2f(100+1400, screenHeight/2 +150));
	m_Layer4.push_back(backTree);

	backTree = new BackTree();
	backTree->Init("BackPalmTreeRegular");
	backTree->setPosition(sf::Vector2f(200+ 1400, screenHeight/2 +110));
	m_Layer4.push_back(backTree);

	backTree = new BackTree();
	backTree->Init("BackPalmTreeRegular");
	backTree->setPosition(sf::Vector2f(350+ 1400, screenHeight/2+100));
	m_Layer4.push_back(backTree);

	//Tree Left
	backTree = new BackTree();
	backTree->Init("BackPalmTreeLeft");
	backTree->setPosition(sf::Vector2f(50.f, screenHeight / 2 + 100));
	m_Layer4.push_back(backTree);

	backTree = new BackTree();
	backTree->Init("BackPalmTreeLeft");
	backTree->setPosition(sf::Vector2f(screenWidth/2+100, screenHeight  - 190));
	m_Layer4.push_back(backTree);
	//Tree Right
	backTree = new BackTree();
	backTree->Init("BackPalmTreeRight");
	backTree->setPosition(sf::Vector2f(screenWidth / 2 + 350, screenHeight - 230));
	m_Layer4.push_back(backTree);

	
}

void BackGround::Draw(sf::RenderWindow *window)
{
	window->draw(m_Layer0);
	for (auto it : m_Layer1)
	{
		it->Draw(window);
	}
	for (auto it : m_Layer2)
	{
		it->Draw(window);
	}
	m_Layer3->Draw(window);
	if (m_AllowDrawTree)
	{
		for (auto it : m_Layer4)
		{
			it->Draw(window);
		}
	}
	
}

void BackGround::Update(float deltaTime)
{
	for (auto it : m_Layer1)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_Layer2)
	{
		it->Update(deltaTime);
	}
	m_Layer3->Update(deltaTime);
	if (m_AllowDrawTree)
	{
		for (auto it : m_Layer4)
		{
			it->Update(deltaTime);
		}
	}
	
}

void BackGround::setAllowDrawTree(bool isAllowDrawTree)
{
	m_AllowDrawTree = isAllowDrawTree;
}
