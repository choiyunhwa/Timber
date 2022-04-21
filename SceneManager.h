#pragma once
#include "sceneID.h"
#include "GameManager.h"
#include "Scene.h"

class SceneManager
{
private:
	SceneID currScene = SceneID::TITLE;
	GameManager* Gamemod;
	Scene* scene;

public:
	SceneID GetCurrScene();
	void ChangeScene(SceneID _sceneID);
	void playScene(SceneID _sceneID);
};

