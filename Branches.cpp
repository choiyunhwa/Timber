#include "Branches.h"

Branches::Branches()
{
	spriteBranches = new Sprite[countBranches];
	sideBranches = new side[countBranches];
}

Branches::~Branches()
{
	delete[] spriteBranches;
	delete[] sideBranches;
}

void Branches::InitializeBranches()
{

    GraphicsManager set;
    set.initializerGraphics();

    for (int i = 0; i < countBranches; i++)
    {
        spriteBranches[i].setTexture(set.GetText(GraphicsID::textureBranch));
        spriteBranches[i].setPosition(-2000, -2000);
        spriteBranches[i].setOrigin(220, 40);

        sideBranches[i] = side::NONE;
    }
}

const int Branches::GetCountBranches()
{
    return countBranches;
}

Sprite* Branches::GetBranchesArray()
{
    return spriteBranches;
}

side* Branches::GetSideBranchesArray()
{
    return sideBranches;
}
