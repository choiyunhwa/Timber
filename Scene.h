#pragma once
#include "Background.h"

class Scene
{
private:
	Background backgraound;
public:
	virtual void Update(){};
	virtual void Draw(){};
};

