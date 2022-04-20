#include "Player.h"

void Player::initializePlayer()
{
	GraphicsManager set;
	set.initializerGraphics();
	spritePlayer.setTexture(set.GetText(GraphicsID::texturePlayer));
	spritePlayer.setPosition(580, 720);
	playerSide = side::LEFT;
}

Sprite Player::GetSpritePlayer()
{
	return spritePlayer;
}
