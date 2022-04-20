#include <SFML/Graphics.hpp>
#include <random>
#include <sstream>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Choice.h"

using namespace sf;
using namespace std;

int main()
{
    static int xpos = 0;
    random_device rd;   
    mt19937 gen(rd());  

    VideoMode vm(1920, 1080); 
    RenderWindow window(vm, "Timber!", Style::Default); 

    Texture textureBack;
    textureBack.loadFromFile("graphics/background.png");
    Texture texturePlayer1;
    texturePlayer1.loadFromFile("graphics/player1.png");
    Texture texturePlayer2;
    texturePlayer2.loadFromFile("graphics/player2.png");
    Texture texturePlayer3;
    texturePlayer3.loadFromFile("graphics/player3.png");

    Sprite spriteBack;
    spriteBack.setTexture(textureBack);
    spriteBack.setPosition(0,0); 
    
    Sprite spritePlayer1;
    spritePlayer1.setTexture(texturePlayer1);
    spritePlayer1.setPosition(600, 500);
    Sprite spritePlayer2;
    spritePlayer2.setTexture(texturePlayer2);
    spritePlayer2.setPosition(800, 500);
    Sprite spritePlayer3;
    spritePlayer3.setTexture(texturePlayer3);
    spritePlayer3.setPosition(1000, 500);

    Choice menu(window.getSize().x,window.getSize().y);

    Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                switch (event.key.code)
                {
                case Keyboard::Left:
                    menu.MoveLeft();
                    break;
                case Keyboard::Right:
                    menu.MoveRight();
                    break;
                case Keyboard::Space:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        //해당하는 캐릭터의 정보를 보내야함.
                        break;
                    case 1:
                        
                        break;
                    case 2:
                        
                        break;
                    }
                    break;
                }
            }         
        }
        window.clear();

        window.draw(spriteBack);
        menu.draw(window);
        window.draw(spritePlayer1);
        window.draw(spritePlayer2);
        window.draw(spritePlayer3);
        window.display();
    }

    return 0;
}