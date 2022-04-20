#include "SceneManager.h"

SceneID SceneManager::GetCurrScene()
{
    return currScene;
}

void SceneManager::ChangeScene(SceneID _sceneID)
{
    currScene = _sceneID;
}
