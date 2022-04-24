#include "Axe.h"



Axe::Axe(GraphicsManager graphics)
{
	spriteAxe.setTexture(graphics.GetTexture(GraphicsID::textureAxe));
}

Axe::Axe()
{
}

const float Axe::GetAXE_POSITION_LEFT()
{
	return AXE_POSITION_LEFT;
}

const float Axe::GetAXE_POSITION_RIGHT()
{
	return AXE_POSITION_RIGHT;
}

void Axe::SetAxePosition(float _left, float _right)
{
	AXE_POSITION_LEFT = _left;
	AXE_POSITION_RIGHT = _right;
}

Sprite Axe::GetSpriteAxe()
{
	return spriteAxe;
}
