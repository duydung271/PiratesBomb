#pragma once
#include <SFML/Graphics.hpp>

#include <fstream>
#include <json.hpp>

using json = nlohmann::json;

class TileMap
	:public sf::Drawable, public sf::Transformable
{
public:
	bool Load(const std::string& nameMap);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform = getTransform();
		for (int i = 0; i < m_listVertexMap.size(); i++)
		{
			states.texture = &m_listTileSet[i];
			target.draw(m_listVertexMap[i], states);
		}
	}
	std::vector<sf::VertexArray> m_listVertexMap;
	std::vector<sf::Texture> m_listTileSet;

	std::string m_DataPath = "..//Data//DataMap//";

};