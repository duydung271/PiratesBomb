#include "ResourceManager.h"

ResourceManagers::ResourceManagers()
{
	std::string dataPath = "..\\Data\\";
	m_TexturePath = dataPath + "Texture\\";
	m_FrameDataPath = dataPath + "FrameData\\";
	m_FontPath = dataPath + "Fonts\\";
}

ResourceManagers::~ResourceManagers()
{
	for (auto it : m_MapTexture)
	{
		if (it.second != nullptr)
		{
			delete it.second;
			it.second = nullptr;
		}
	}
	m_MapTexture.clear();
	for (auto it : m_MapFrameData)
	{
		if (it.second != nullptr)
		{
			delete it.second;
			it.second = nullptr;
		}
	}
	m_MapFrameData.clear();
	for (auto it : m_MapFont)
	{
		if (it.second != nullptr)
		{
			delete it.second;
			it.second = nullptr;
		}
	}
	m_MapFont.clear();
}


void ResourceManagers::AddTexture(const std::string& name)
{
	auto it = m_MapTexture.find(name);
	if (it != m_MapTexture.end())
	{
		return;
	}
	std::string path = m_TexturePath + name + ".png";
	sf::Texture* texture=new sf::Texture();
	texture->loadFromFile(path);

	m_MapTexture.insert(std::pair <std::string, sf::Texture*>(name,texture));
}

void ResourceManagers::AddFrameData(const std::string& name)
{
	auto it = m_MapFrameData.find(name);
	if (it != m_MapFrameData.end())
	{
		return;
	}
	FrameData* framedata = new FrameData();
	std::string path = m_FrameDataPath + name + ".data";
	framedata->LoadFile(path);

	m_MapFrameData.insert(std::pair <std::string, FrameData*>(name, framedata));
}

void ResourceManagers::AddFont(const std::string& name)
{
	auto it = m_MapFont.find(name);
	if (it != m_MapFont.end())
	{
		return;
	}
	std::string path = m_FontPath + name + ".ttf";
	sf::Font* Font = new sf::Font();
	Font->loadFromFile(path);

	m_MapFont.insert(std::pair <std::string, sf::Font*>(name, Font));
}


void ResourceManagers::RemoveTexture(const std::string& name)
{
	auto it = m_MapTexture.find(name);
	if (it != m_MapTexture.end())
	{
		if (it->second != nullptr)
		{
			delete it->second;
			it->second = nullptr;
		}
		m_MapTexture.erase(name);
	}
}

void ResourceManagers::RemoveFrameData(const std::string& name)
{
	auto it = m_MapFrameData.find(name);
	if (it != m_MapFrameData.end())
	{
		if (it->second != nullptr)
		{
			delete it->second;
			it->second = nullptr;
		}
		m_MapFrameData.erase(name);
	}
}

void ResourceManagers::RemoveFont(const std::string& name)
{
	auto it = m_MapFont.find(name);
	if (it != m_MapFont.end())
	{
		if (it->second != nullptr)
		{
			delete it->second;
			it->second = nullptr;
		}
		m_MapFont.erase(name);
	}
}


sf::Texture* ResourceManagers::GetTexture(const std::string& name)
{
	auto it = m_MapTexture.find(name);
	if (it != m_MapTexture.end())
	{
		return it->second;
	}
	std::string path = m_TexturePath + name + ".png";
	sf::Texture *texture=new sf::Texture();
	texture->loadFromFile(path);
	m_MapTexture.insert(std::pair <std::string, sf::Texture*>(name, texture));
	return texture;

}

FrameData* ResourceManagers::GetFrameData(const std::string& name)
{
	auto it = m_MapFrameData.find(name);
	if (it != m_MapFrameData.end())
	{
		return it->second;
	}
	FrameData* framedata = new FrameData();
	std::string path = m_FrameDataPath + name + ".data";
	framedata->LoadFile(path);

	m_MapFrameData.insert(std::pair <std::string, FrameData*>(name, framedata));
	return framedata;
}

sf::Font* ResourceManagers::GetFont(const std::string& name)
{
	auto it = m_MapFont.find(name);
	if (it != m_MapFont.end())
	{
		return it->second;
	}
	std::string path = m_FontPath + name + ".ttf";
	sf::Font* Font = new sf::Font();
	Font->loadFromFile(path);

	m_MapFont.insert(std::pair <std::string, sf::Font*>(name, Font));
	return Font;
}
