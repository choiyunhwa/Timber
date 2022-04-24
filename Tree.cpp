#include "Tree.h"


Tree::Tree(GraphicsManager _graphics)
{
	spriteTree.setTexture(_graphics.GetTexture(GraphicsID::textureTree));
	
	log = _graphics;

	
}

Sprite Tree::GetspriteTree()
{
	return spriteTree;
}
