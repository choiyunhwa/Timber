#include "Title.h"

Title::Title(Text showTitle)
{
	
	showTitle.setString("");

}

void Title::Font()
{	
	fontKOMIKAP.loadFromFile("fonts/KOMIKAP_.ttf");
	showTitle.setFont(fontKOMIKAP);
	showTitle.setCharacterSize(100);
	showTitle.setFillColor(Color::Yellow);
}

void Title::titlePos()
{

}
