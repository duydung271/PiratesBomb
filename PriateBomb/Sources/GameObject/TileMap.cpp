#pragma warning(disable : 4996)

#include "TileMap.h"
int IndexPos(std::vector<int> data)
{
	for (auto it : data)
	{
		if (it != 0) return it;
	}
	return 0;
}

bool TileMap::Load(const std::string& nameMap)
{
	// read a JSON file
	std::ifstream is(m_DataPath+nameMap);
	json js;
	is >> js;

	int numTileArray = 0;
	for (auto it : js["layers"])
	{
		std::vector<int> tilePos;
		for (auto data : it["data"])
		{
			tilePos.push_back(data);
		}

		sf::Texture tileSet;
		sf::VertexArray vertexArray;

		int dk = IndexPos(tilePos);
		int SoDu = 1;
		std::string linkTile = "";
		for (auto tile : js["tilesets"])
		{
			if (dk - tile["firstgid"].get<int>() >= 0)
			{
				linkTile = tile["source"].get<std::string>();
				SoDu = tile["firstgid"].get<int>();
			}
		}

		std::ifstream isT(m_DataPath+linkTile);
		json jsTile;
		isT >> jsTile;

		if (!tileSet.loadFromFile(m_DataPath+jsTile["name"].get<std::string>() + ".png")) return false;
		tileSet.setSmooth(true);

		vertexArray.setPrimitiveType(sf::Quads);
		int width = js["width"];
		int height = js["height"];
		sf::Vector2u tileSize(js["tilewidth"], js["tileheight"]);


		vertexArray.resize(width * height * 4);

		for (int i = 0; i < width; ++i)
		{
			for (int j = 0; j < height; ++j)
			{
				int tileNumber = tilePos[i + j * width] - SoDu;
				if (tileNumber < 0) continue;
				//std::cout << tileNumber << " ";
				int tu = tileNumber % (tileSet.getSize().x / tileSize.x);
				int tv = tileNumber / (tileSet.getSize().x / tileSize.x);

				// get a pointer to the current tile's quad
				sf::Vertex* quad = &vertexArray[(i + j * width) * 4];

				// define its 4 corners
				quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
				quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
				quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
				quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

				// define its 4 texture coordinates
				quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
				if (jsTile.contains("tiles"))
				{
					
					for (auto it : jsTile["tiles"])
					{
						if (it["id"] == tileNumber)
						{
							for (auto pr : it["properties"])
							{
								if (pr["name"] == "Visitable")
								{
									if (pr["value"] == false)
									{
										World::GetInstance()->CreateGround(b2Vec2((i + 0.5f) * tileSize.x, (j + 0.5f) * tileSize.y),b2Vec2( tileSize.x, tileSize.y));
									}
								}
							}
							break;
						}
					}
				}
			}
		}
		m_listVertexMap.push_back(vertexArray);
		m_listTileSet.push_back(tileSet);
	}
	return true;

}
