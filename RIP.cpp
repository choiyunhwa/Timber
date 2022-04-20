#include "RIP.h"

void RIP::initializeRIP()
{
	GraphicsManager set;
	set.initializerGraphics();

	spriteRIP.setTexture(set.GetText(GraphicsID::textureRIP));
	spriteRIP.setPosition(600, 860);
}

Sprite RIP::GetspriteRIP()
{
	return spriteRIP;
}
