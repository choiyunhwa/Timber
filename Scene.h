#pragma once
#include "Background.h"
#include "GraphicsManager.h"
#include "UiManager.h"

class Scene
{
private:
	Background backgraound;
public:
	virtual void Update(UiManager& ui , RenderWindow& _window){};
	virtual void Draw(UiManager& ui, RenderWindow& _window){};
};

