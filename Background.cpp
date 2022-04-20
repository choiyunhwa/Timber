#include "Background.h"

void Background::InitializeBackground()
{
	GraphicsManager set;
	set.initializerGraphics();

	background.setTexture(set.GetText(GraphicsID::textureBackground));
	background.setPosition(0, 0);

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			moveObject[i].setTexture(set.GetText(GraphicsID::textureCloud));
		}
		else
		{
			moveObject[i].setTexture(set.GetText(GraphicsID::textureBee));
		}
		moveObject[i].setPosition(2000, 0);
		moveActivate[i] = false;
		moveSpeed[i] = 0.f;
	}

}
