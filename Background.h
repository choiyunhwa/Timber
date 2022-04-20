#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicsManager.h"

using namespace sf;
class Background
{
private:
	Sprite background;
	Sprite moveObject[4];
	bool moveActivate[4];
	float moveSpeed[4];
public:
	void InitializeBackground();
};

