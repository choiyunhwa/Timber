#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"
#include "GraphicsManager.h"
#include "Axe.h"

using namespace sf;
class Player
{
private:
	Sprite spritePlayer;
	Axe playerAxe;
	side playerSide;

public:
	Player(GraphicsManager _graphics);
	void initializePlayer();
	Sprite GetSpritePlayer();
	void SetSide(side _byside);

};

