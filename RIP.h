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
	void initializeRIP();
	Sprite GetspriteRIP();
};

