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

void Framework::Release()
{
	//scene change 시 init해줘야하는거 새로 초기화
}
