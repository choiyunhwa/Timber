#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"
#include "GraphicsManager.h"

using namespace sf;
class Tree
{
private:
	Sprite spriteTree;
public:
	void InitializeTree();
	Sprite GetspriteTree();
};

