#include "Title.h"

void Title::title1()
{
	
	fontKOMIKAP.loadFromFile("fonts/KOMIKAP_.ttf");
	Title1.setString("TIMBER");
	Title1.setFont(fontKOMIKAP);
	Title1.setCharacterSize(100);
	Title1.setFillColor(Color::Yellow);
	Title1.setPosition(780, 200);
}


void Title::title2()
{
	Title2.setString("MAN");
	Title2.setFont(fontKOMIKAP);
	Title2.setCharacterSize(90);
	Title2.setFillColor(Color::Yellow);
	Title2.setPosition(890, 300);
}

	


void Title::Update()
{
	window.draw(Title1);
	window.draw(Title2);
}
