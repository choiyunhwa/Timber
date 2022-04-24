#pragma once
#include "Scene.h"
#include "Gamemod.h"
#include "GamemodID.h"
#include "Gamemod_singlemod.h"
#include "Gamemod_LocalMulti2player.h"

class GamePlay : public Scene
{
private:
	Gamemod* mod;
public:
	GamePlay(GamemodID _ID);
};

