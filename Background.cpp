#include "Background.h"

Background::Background(GraphicsManager _graphics)
{
	background.setTexture(_graphics.GetTexture(GraphicsID::textureBackground));

	background.setPosition(0, 0);

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			moveObject[i].setTexture(_graphics.GetTexture(GraphicsID::textureCloud));
		}
		else
		{
			moveObject[i].setTexture(_graphics.GetTexture(GraphicsID::textureBee));
		}
		moveObject[i].setPosition(2000, 0);
		moveActivate[i] = false;
		moveSpeed[i] = 0.f;
	}
}

Background::Background()
{
}

Sprite Background::GetBackground()
{
	return background;
}

Sprite* Background::moveObjectArray()
{
	return moveObject;
}

bool* Background::moveActivateArray()
{
	return moveActivate;
}

float* Background::moveSpeedArray()
{
	return moveSpeed;
}
