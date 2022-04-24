#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"
#include "GraphicsManager.h"

using namespace sf;
class Axe
{
private:
	Sprite spriteAxe;
	float AXE_POSITION_LEFT = 0;
	float AXE_POSITION_RIGHT = 0;
public:
	Axe();
	Axe(GraphicsManager _graphics);
	const float GetAXE_POSITION_LEFT();
	const float GetAXE_POSITION_RIGHT();
	void SetAxePosition(float _left, float _right);

	Sprite GetSpriteAxe();

};

