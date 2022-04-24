#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"
#include "GraphicsManager.h"
#include "Branches.h"
#include "Log.h"

using namespace sf;
class Tree
{
private:
	Sprite spriteTree;
	Branches TreeBranches;
	Log log;
public:
	Tree(GraphicsManager _graphics);
	Sprite GetspriteTree();
};

