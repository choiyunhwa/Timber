#include "Framework.h"

void Framework::Initialize()
{
	graphics.initializerGraphics();
	sound.InitializeSound();
	Ui.InitializeUI();
}

void Framework::Update()
{
	scene.playScene()->Update(Ui, window);
	scene.playScene();

	//scene ���� ������Ʈ �Ǵ� �κ��� ���⼭ ó�� 
	//eX) Ű�Է�, ��������Ʈ ��ġ ���� ���
}

void Framework::Draw()
{
	scene.playScene()->Draw(Ui, window);
	
	//�� �̷����� �ɰ� ����

	//������Ʈ �� ������Ʈ�� UI�� ���⼭ ��� 
}

void Framework::Release()
{
	//scene change �� init������ϴ°� ���� �ʱ�ȭ
}
