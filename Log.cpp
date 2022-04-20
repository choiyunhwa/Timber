#include "Log.h"

void Log::InitializeLog()
{
	GraphicsManager set;
	set.initializerGraphics();
	spritelog.setTexture(set.GetText(GraphicsID::textureLog));
	spritelog.setPosition(810, 720);

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
