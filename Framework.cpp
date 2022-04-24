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

	//scene 마다 업데이트 되는 부분을 여기서 처리 
	//eX) 키입력, 스프라이트 위치 조정 등등
}

void Framework::Draw()
{
	scene.playScene()->Draw(Ui, window);
	
	//뭐 이런식이 될거 같음

	//업데이트 된 오브젝트나 UI를 여기서 출력 
}

void Framework::Release()
{
	//scene change 시 init해줘야하는거 새로 초기화
}
