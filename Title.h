#pragma once
#include "Scene.h"
#include "UiManager.h"

class Title : public Scene
{
public:
	void Update(UiManager& ui);
	
	void Draw();

	//�����Ҷ� ��µǴ� ȭ��, Ű�Է½� �޴��� �̵��ϰ� �ϱ�. scene manager�� �ִ� chnageScene�� ���ؼ� �ٲ�����ؿ�~.
};

