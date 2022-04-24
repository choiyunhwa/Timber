#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"
#include "GraphicsManager.h"

using namespace sf;
class RIP
{
private:
	Sprite spriteRIP;
	
public:
	RIP(GraphicsManager _grapics);

	void SetRIPPos(Vector2f _deadPlayPos);

	Sprite GetspriteRIP();
};

