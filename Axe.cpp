#include "Axe.h"

void Axe::initializeAxe()
{
	GraphicsManager set;
	set.initializerGraphics();
	
	spriteAxe.setTexture(set.GetText(GraphicsID::textureAxe));
	spriteAxe.setPosition(700, 830);
}

const float Axe::GetAXE_POSITION_LEFT()
{
	return AXE_POSITION_LEFT;
}

const float Axe::GetAXE_POSITION_RIGHT()
{
	return AXE_POSITION_RIGHT;
}

Sprite Axe::GetSpriteAxe()
{
	return spriteAxe;
}
