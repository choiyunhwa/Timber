#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"
#include "GraphicsManager.h"

using namespace sf;
class Branches
{
private:
	const int countBranches = 6;
	Sprite * spriteBranches;
	side * sideBranches;
public:
	Branches();
	~Branches();

	void InitializeBranches();
	const int GetCountBranches();
	Sprite* GetBranchesArray();
	side* GetSideBranchesArray();
};

