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
	//scene change �� init������ϴ°� ���� �ʱ�ȭ
}
