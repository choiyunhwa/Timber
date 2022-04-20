#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"
#include "GraphicsManager.h"

using namespace sf;
class Axe
{
private:
	Sprite spriteAxe;
	const float AXE_POSITION_LEFT = 700;
	const float AXE_POSITION_RIGHT = 1075;
public:
	void initializeAxe();
	const float GetAXE_POSITION_LEFT();
	const float GetAXE_POSITION_RIGHT();
	Sprite GetSpriteAxe();

};

