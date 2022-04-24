#include "Log.h"

Log::Log()
{
}

Log::Log(GraphicsManager _graphics)
{
	spritelog.setTexture(_graphics.GetTexture(GraphicsID::textureLog));

	logActive = false;
	logSpeedX = 1000;
	logSpeedY = -1500;
}

Sprite Log::GetSpriteLog()
{
	return spritelog;
}

void Log::SetLogActive(bool _check)
{
	logActive = _check;
}

void Log::SetLogSpeedX(float _X)
{
	logSpeedX = _X;
}
