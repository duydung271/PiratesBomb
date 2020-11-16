#pragma once
#include <SFML/Graphics.hpp>
#include "../GameConfig.h"
class LayerShadow: public sf::RectangleShape
{
public:
	LayerShadow();
	~LayerShadow();
	void setAlphaMax(int alpha);
	void setAlphaMin(int alpha);
	
	void Update(float deltaTime);
	void setDir(bool alphaIsUp);//Huong tang giam cua alpha

	bool isEnd();
	bool alphaIsUp();

private:
	bool m_alphaIsUp;
	int m_alphaMax;
	int m_alphaMin;
	int m_CurrentAlpha;

	float m_CurrentTime;
	float m_FrameTime;

};