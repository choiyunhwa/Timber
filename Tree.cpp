#include "Tree.h"

void Tree::InitializeTree()
{
	GraphicsManager set;
	set.initializerGraphics();

	spriteTree.setTexture(set.GetText(GraphicsID::textureTree));
	spriteTree.setPosition(810, 0);
}

Sprite Tree::GetspriteTree()
{
	return spriteTree;
}
