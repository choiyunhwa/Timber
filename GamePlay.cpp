#include "GamePlay.h"

GamePlay::GamePlay(GamemodID _ID)
{
	switch (_ID)
	{
	case GamemodID::SINGLE_MOD:
		mod = new Gamemod_singlemod;
		break;
	case GamemodID::LOCAL_MULTI:
		mod = new Gamemod_LocalMulti2player;
		break;
	}
}
