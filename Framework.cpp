#include "Framework.h"

void Framework::Initialize()
{
	graphics.initializerGraphics();
	sound.InitializeSound();
	Ui.InitializeUI();
}

Framework::Framework()
{
	isPause = true;
	acceptInput = false;

}

void Framework::Update()
{
	currScene.playScene()->Update(Ui, window);
}

void Framework::Draw()
{
	currScene.playScene()->Draw(Ui, window);

}

void Framework::Release()
{
	
}
