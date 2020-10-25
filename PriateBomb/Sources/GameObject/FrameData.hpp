#pragma once
#include "../GameManager/ResourceManager.h"
#include <fstream>
class FrameData
{
public:
	FrameData() {}
	void LoadFile(const std::string& path)
	{
		std::fstream Input;
		Input.open(path);
		Input >> Name;

		std::string tmp;
		Input >> tmp;
		Input >> Width;

		Input >> tmp;
		Input >> Height;

		Input >> tmp;
		Input >> NumFrame.x;

		Input >> tmp;
		Input >> NumFrame.y;

		NumFrameInRow.resize(NumFrame.y);
		FrameTime.resize(NumFrame.y);
		for (int i = 0; i < NumFrame.y;i++)
		{
			int t;
			Input >> t;
			Input >> tmp;
			Input >> NumFrameInRow[t];
			Input >> FrameTime[t];
		}
		Input.close();

	}
	std::string Name;
	int Width, Height;
	sf::Vector2u NumFrame;
	std::vector<unsigned int> NumFrameInRow;
	std::vector<float> FrameTime;
};