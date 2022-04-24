#pragma once
#include "sceneID.h"
#include "GameManager.h"
#include "Scene.h"
#include "Title.h"
#include "MENU.h"
#include "Gamemod_singlemod.h"
#include "SelectCharacter.h"
#include "Gamemode.h"
#include "GamePlay.h"

class SceneManager
{
private:
	SceneID currScene = SceneID::TITLE;
	GameManager GameManager;
	Scene* scene;

	
public:
	SceneManager();

	SceneID GetCurrScene();
	void ChangeScene(SceneID _sceneID);
	Scene* playScene();
	void SetGamemod(GamemodID _setId);

	~SceneManager();
};

