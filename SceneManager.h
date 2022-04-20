#pragma once
#include "sceneID.h"
class SceneManager
{
private:
	SceneID currScene = SceneID::TITLE;
public:
	SceneID GetCurrScene();
	void ChangeScene(SceneID _sceneID);
};

