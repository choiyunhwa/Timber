#include "GraphicsManager.h"

void GraphicsManager::initializerGraphics()
{
	textureBackground.loadFromFile("graphics/background.png");
	textureCloud.loadFromFile("graphics/cloud.png");
	textureBee.loadFromFile("graphics/Bee.png");
	textureBranch.loadFromFile("graphics/branch.png");
	texturePlayer.loadFromFile("graphics/player.png");
	textureRIP.loadFromFile("graphics/rip.png");
	textureAxe.loadFromFile("graphics/axe.png");
	textureLog.loadFromFile("graphics/log.png");
	textureTree.loadFromFile("graphics/Tree.png");

}

Texture GraphicsManager::GetTexture(GraphicsID _id)
{
	switch (_id)
	{
	case GraphicsID::textureBackground:
		return textureBackground;
		break;
	case GraphicsID::textureCloud:
		return textureCloud;
		break;
	case GraphicsID::textureBee:
		return textureBee;
		break;
	case GraphicsID::textureBranch:
		return textureBranch;
		break;
	case GraphicsID::texturePlayer:
		return texturePlayer;
		break;
	case GraphicsID::textureRIP:
		return textureRIP;
		break;
	case GraphicsID::textureAxe:
		return textureAxe;
		break;
	case GraphicsID::textureLog:
		return textureLog;
		break;
	case GraphicsID::textureTree:
		return textureTree;
		break;
	default:
		break;
	}
}
