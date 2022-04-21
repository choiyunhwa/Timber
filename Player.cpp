#include "Player.h"

void Player::initializePlayer()
{
	GraphicsManager set;
	set.initializerGraphics();
	playerAxe.initializeAxe();

	spritePlayer.setTexture(set.GetText(GraphicsID::texturePlayer));
	spritePlayer.setPosition(580, 720);
	playerSide = side::LEFT;
}

Sprite Player::GetSpritePlayer()
{
	return spritePlayer;
}

void Player::SetSide(side _byside)
{
	playerSide = _byside;
}
