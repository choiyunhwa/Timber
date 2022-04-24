#include "GameManager.h"



GameManager::GameManager()
{
	currGamemod = new Gamemod_singlemod;
}

void GameManager::SelectGamemod(GamemodID _select)
{
	delete currGamemod;
	switch (_select)
	{
	case GamemodID::SINGLE_MOD:
		currGamemod = new Gamemod_singlemod;
		break;
	case GamemodID::LOCAL_MULTI:
		currGamemod = new Gamemod_LocalMulti2player;
		break;
	}
}
