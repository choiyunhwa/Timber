#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicsID.h"
using namespace sf;
class GraphicsManager
{
private:
	Texture textureBackground;
	Texture textureCloud;
	Texture textureBee;
	Texture textureBranch;
	Texture texturePlayer;
	Texture textureRIP;
	Texture textureAxe;
	Texture textureLog;
	Texture textureTree;
public:
	void initializerGraphics();
	Texture GetTexture(GraphicsID _id);


};

