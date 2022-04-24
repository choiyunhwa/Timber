#include "SceneManager.h"

SceneID SceneManager::GetCurrScene()
{
    return currScene;
}

SceneManager::SceneManager()
{
	scene = new Title;
}

void SceneManager::ChangeScene(SceneID _sceneID)
{
    currScene = _sceneID;

	delete scene;
	switch (currScene)
	{
	case SceneID::TITLE:
		scene = new Title;
		break;
	//case SceneID::MENU:
	//	scene = new MENU;
	//	break;
	//case SceneID::GAMEMODE:
	//	scene = new Gamemode;
	//	break;
	//case SceneID::SELECTCHARACTOR:
	//	scene = new SelectCharacter;
	//	break;
	//case SceneID::GAMEPLAY:
	//	scene = new GamePlay;
		break;
	}
}

Scene* SceneManager::playScene()
{
	return scene;
}

SceneManager::~SceneManager()
{
	delete scene;
}

void SceneManager::SetGamemod(GamemodID _setId)
{
	GameManager.SelectGamemod(_setId);
}
