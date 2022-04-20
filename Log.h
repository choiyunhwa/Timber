#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"
#include "GraphicsManager.h"

using namespace sf;
class Log
{
private:
	Sprite spritelog;
	bool logActive; 
	float logSpeedX;
	float logSpeedY;
public:
	void InitializeLog();
	Sprite GetSpriteLog();

	void SetLogActive(bool _check);
	void SetLogSpeedX(float _X);
};

