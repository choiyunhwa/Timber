#include "Branches.h"

Branches::Branches()
{
}

Branches::Branches(GraphicsManager _graphics)
{
    spriteBranches.setTexture(_graphics.GetTexture(GraphicsID::textureBranch));

    for (int i = 0; i < countBranches; i++)
    {
        sideBranches[i] = side::NONE;
    }
}


const int Branches::GetCountBranches()
{
    return countBranches;
}

Sprite Branches::GetBranches()
{
    return spriteBranches;
}

side* Branches::GetSideBranchesArray()
{
    return sideBranches;
}
