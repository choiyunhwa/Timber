#pragma once
#include "Scene.h"
#include "UiManager.h"

class Title : public Scene
{
public:
	void Update(UiManager& ui);
	
	void Draw();

	//시작할때 출력되는 화면, 키입력시 메뉴로 이동하게 하기. scene manager에 있는 chnageScene을 통해서 바꿔줘야해요~.
};

