#pragma once
#include "Framework.h"
#include "Scene.h"
#include "UiManager.h"
#include "GameManager.h"
#include "Background.h"

class Title : public Scene
{
private:
	Background background;
	UiManager Ui;

public:
	Title();
	
};

