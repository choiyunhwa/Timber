#pragma once
#include "GraphicsManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "UiManager.h"
#include "Background.h"
#include "Branches.h"
#include "Player.h"
#include "RIP.h"
#include "Axe.h"
#include "Log.h"
#include "Tree.h"

#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;
using namespace std;

class Framework
{
private:
	RenderWindow window;

	random_device rd;
	mt19937 gen;
	
	bool isPause;
	bool acceptInput;

	Clock clock;
	
	GraphicsManager graphics;
	SceneManager scene;
	SoundManager sound;
	UiManager Ui;

	Background backgrounds;
	Branches branches;
	Player player;
	RIP rip;
	Axe axe;
	Log log;
	Tree tree;

public:

	void Initialize();

	void Update();

	void Draw();

	void Release();
};

	