#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Title
{
private:
	Text showTitle;
    Font fontKOMIKAP;
    FloatRect titleRect;

public:
    Title(Text showTitle);
    void Font();
    void titlePos();




};



/*
 textScore.setFont(fontKOMIKAP);
 textScore.setString("Score = 0");
 extScore.setCharacterSize(100)
 textScore.setFillColor(Color::White);


    FloatRect textRect = textMessage.getLocalBounds(); //����ü - �߾��� ���
    textMessage.setOrigin(
        textRect.left + textRect.width * 0.5f,
        textRect.top + textRect.height * 0.5f
        window.draw(textScore);

*/ 