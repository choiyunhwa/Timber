#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"
#include "GraphicsManager.h"

using namespace sf;
class Player
{
private:
	Sprite spritePlayer;
	side playerSide;
public:
	void initializePlayer();
	Sprite GetSpritePlayer();
	void SetSide(side _byside);

};

