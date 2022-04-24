#pragma once
#include "Background.h"

class Scene
{
private:
	Background backgraound;
public:
	virtual void Update(UiManager& ui , Framework& _window){};
	virtual void Draw(UiManager& ui, Framework& _window){};
};

