#pragma once
#include "Gamemod.h"
#include "Gamemod_singlemod.h"
#include "Gamemod_LocalMulti2player.h"
#include "GamemodID.h"

class GameManager
{
private:
	Gamemod* currGamemod;
public:
	GameManager();
	void SelectGamemod(GamemodID _select);
};

