#include "Framework.h"

void Framework::Initialize()
{
	graphics.initializerGraphics();
	sound.InitializeSound();
	Ui.InitializeUI();
}

void Framework::Update()
{
	scene.playScene()->Update();
}

void Framework::Draw()
{
	scene.playScene()->Draw();
}
