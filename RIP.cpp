#include "RIP.h"


RIP::RIP(GraphicsManager _grapics)
{
	spriteRIP.setTexture(_grapics.GetTexture(GraphicsID::textureRIP));
}

void RIP::SetRIPPos(Vector2f _deadPlayPos)
{
	spriteRIP.setPosition(_deadPlayPos);
}

Sprite RIP::GetspriteRIP()
{
	return spriteRIP;
}
