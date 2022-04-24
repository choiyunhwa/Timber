#include "Player.h"

Player::Player(GraphicsManager _graphics)
{
	spritePlayer.setTexture(_graphics.GetTexture(GraphicsID::texturePlayer));
	playerAxe = _graphics;
	playerSide = side::LEFT;

	playerAxe.SetAxePosition(700, 1075);


}

void Player::initializePlayer()
{
	
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
