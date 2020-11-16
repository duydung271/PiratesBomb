#ifndef  RESOURCEMANAGER_H
#define  RESOURCEMANAGER_H

#include <map>
#include <iostream>
#include <string>
#include "Singleton.h"
#include "..\GameConfig.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "../GameObject/FrameData.hpp"
#include "../GameObject/World.h"
#include "../GameObject/Entity.h"
#include "../GameObject/AnimationComponent.h"

class ResourceManagers : public CSingleton<ResourceManagers>
{
public:
	ResourceManagers();
	~ResourceManagers();

	void AddTexture(const std::string& name);
	void AddFrameData(const std::string& name);
	void AddFont(const std::string& name);

	void RemoveTexture(const std::string& name);
	void RemoveFrameData(const std::string& name);
	void RemoveFont(const std::string& name);

	sf::Texture* GetTexture(const std::string& name);
	FrameData* GetFrameData(const std::string& name);
	sf::Font* GetFont(const std::string& name);

private:
	std::map<std::string, sf::Texture*> m_MapTexture;
	std::map<std::string, FrameData* > m_MapFrameData;
	std::map<std::string, sf::Font* > m_MapFont;

	std::string m_TexturePath;
	std::string m_FrameDataPath;
	std::string m_FontPath;
};
#endif // ! RESOURCEMANAGER_H
