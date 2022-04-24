#pragma once
#include "GraphicsManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "UiManager.h"
#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;
using namespace std;

class Framework
{
private:
	SceneManager currScene;
	SoundManager sound;
	GraphicsManager graphics;
	UiManager Ui;

	VideoMode vm;
	RenderWindow window = { vm,"Timber!",Style::Default };

	bool isPause;
	bool acceptInput;

public:
	Framework();
	
	void Initialize();

	void Update();

	void Draw();

	void Release();
};

	