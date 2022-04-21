#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"
#include "GraphicsManager.h"
#include "Framework.h"

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

    void UpdateBranches(side sides[], int length, mt19937& gen)
    {
        for (int i = length - 1; i >= 0; --i)
        {
            sides[i] = sides[i - 1];
        }
        int rnd = gen() % 5;

        switch (rnd)
        {
        case 1:
            sides[0] = side::LEFT;
            break;
        case 2:
            sides[0] = side::RIGHT;
            break;
        default:
            sides[0] = side::NONE;
            break;
        }
    }

};

