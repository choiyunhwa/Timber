#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
//#include "Scene.h"

class Title : public Scene
{
private:
    Text Title1;
    Text Title2;
    Font fontKOMIKAP;

   

public:
   
    void title1();
    void title2();
    void Update();

};
