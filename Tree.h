#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"
#include "GraphicsManager.h"
#include "Branches.h"

using namespace sf;
class Tree
{
private:
	Sprite spriteTree;
	Branches TreeBranches;
public:
	void InitializeTree();
	Sprite GetspriteTree();
};

