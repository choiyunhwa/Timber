#include <SFML/Graphics.hpp>
#include <random>
#include <sstream>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

enum class side
{
    LEFT,
    RIGHT,
    NONE
};


//나무가지를 한칸씩 내려줌
void UpdateBranches(side sides[], int length, mt19937& gen)
{
    for (int i = length - 1; i >= 0; --i)
    {
        sides[i] = sides[i - 1];
    }
    int rnd = gen() % 5;

    switch (rnd)
    {
    case 1:
        sides[0] = side::LEFT;
        break;
    case 2:
        sides[0] = side::RIGHT;
        break;
    default:
        sides[0] = side::NONE;
        break;
    }
}

int main()
{


    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.

    VideoMode vm(1920, 1080); //해상도 정보가 들어있음(추가로 다른 인자를 가지고 올 수 있음
    RenderWindow window(vm, "Timber!", Style::Default);

    Font fontKOMIKAP;
    fontKOMIKAP.loadFromFile("fonts/KOMIKAP_.ttf"); //폰트 파일 불러오기
    
    /*----------------------------------------------------------------------------*/
    /*---------------------------------MENU-------------------------------------*/
    /*----------------------------------------------------------------------------*/
    bool menuOn = true;

    Text menu[4];
    menu[0].setFont(fontKOMIKAP);
    menu[1].setFont(fontKOMIKAP);
    menu[2].setFont(fontKOMIKAP);
    menu[3].setFont(fontKOMIKAP);

    menu[0].setCharacterSize(30);
    menu[1].setCharacterSize(30);
    menu[2].setCharacterSize(30);
    menu[3].setCharacterSize(30);

    menu[0].setPosition(1920.f * 0.5 - 100, 500);
    menu[1].setPosition(1920.f * 0.5 - 100  ,600);
    menu[2].setPosition(1920.f * 0.5 - 100  ,700);
    menu[3].setPosition(1920.f * 0.5 - 100 ,800);

    menu[0].setFillColor(Color (85, 58, 28,255));
    menu[1].setFillColor(Color(85, 58, 28, 255));
    menu[2].setFillColor(Color(85, 58, 28, 255));
    menu[3].setFillColor(Color(85, 58, 28, 255));


    menu[0].setString("Play");
    menu[1].setString("Game mode");
    menu[2].setString("Characters");
    menu[3].setString("Exit");

    RectangleShape menuBox[4];
    menuBox[0].setFillColor(Color(252, 241, 207,255));
    menuBox[1].setFillColor(Color(252, 241, 207, 255));
    menuBox[2].setFillColor(Color(252, 241, 207, 255));
    menuBox[3].setFillColor(Color(252, 241, 207, 255));

    menuBox[0].setSize(Vector2f(200, 50));
    menuBox[1].setSize(Vector2f(200,50));
    menuBox[2].setSize(Vector2f(200, 50));
    menuBox[3].setSize(Vector2f(200, 50));

    menuBox[0].setPosition(1920.f * 0.5 - 100, 500);
    menuBox[1].setPosition(1920.f * 0.5 - 100, 600);
    menuBox[2].setPosition(1920.f * 0.5 - 100, 700);
    menuBox[3].setPosition(1920.f * 0.5 - 100, 800);




    int menuIndex = 0;
    menuBox[menuIndex].setFillColor(Color(180, 180, 80, 255));


    int SelIndex = 0;
    bool selModeOn = false;
    Text selCh[2];
     RectangleShape selGame[2];

     selCh[0].setFont(fontKOMIKAP);
     selCh[1].setFont(fontKOMIKAP);

     selCh[0].setCharacterSize(30);
     selCh[1].setCharacterSize(30);

     selCh[0].setPosition(1920.f * 0.5 - 100, 600);
     selCh[1].setPosition(1920.f * 0.5 - 100, 700);

     selCh[0].setFillColor(Color(85, 58, 28, 255));
     selCh[1].setFillColor(Color(85, 58, 28, 255));

     selCh[0].setString("Solo");
     selCh[1].setString("Dual");


    selGame[0].setFillColor(Color(252, 241, 207, 255));
    selGame[0].setSize(Vector2f(200, 50));
    selGame[0].setPosition(1920.f * 0.5 - 100, 600);

    selGame[1].setFillColor(Color(252, 241, 207, 255));
    selGame[1].setSize(Vector2f(200, 50));
    selGame[1].setPosition(1920.f * 0.5 - 100, 700);
























    /*----------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------*/


    Text textMessage; //폰트를 드로우 하는 과정?
    textMessage.setFont(fontKOMIKAP);
    Text textScore;
    textScore.setFont(fontKOMIKAP);


    textMessage.setString("Press Enter to start!"); // 글씨 입력
    textScore.setString("Score = 0");

    textMessage.setCharacterSize(75); //폰트사이즈
    textScore.setCharacterSize(100);

    textMessage.setFillColor(Color::White); //글씨 색상 지정
    textScore.setFillColor(Color::White);

    textScore.setPosition(20, 20);

    FloatRect textRect = textMessage.getLocalBounds(); //구조체 - 중앙점 계산
    textMessage.setOrigin(
        textRect.left + textRect.width * 0.5f,
        textRect.top + textRect.height * 0.5f
    );





    textMessage.setPosition(1920 * 0.5f, 1080 * 0.5f); // 초기화가 됨

    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png"); //텍스처 로드

    Sprite spriteBackground;//드로우 하는 과정을 담당
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");

    Sprite spriteCloud1;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud1.setPosition(2000, 0);

    Sprite spriteCloud2;
    spriteCloud2.setTexture(textureCloud);
    spriteCloud2.setPosition(2000, 0);

    Sprite spriteCloud3;
    spriteCloud3.setTexture(textureCloud);
    spriteCloud3.setPosition(2000, 0);

    bool cloudActive = false; // 상태를 표현하는 변수 ( 화면 안에 있을때 true, 화면 밖에있을때 false )//시작하는 위치 //플래그 변수
    float clodeSpeed = 0.f;

    Texture textureBee;
    textureBee.loadFromFile("graphics/Bee.png");

    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(2000, 0);

    bool beeActive = false; // 상태를 표현하는 변수 ( 화면 안에 있을때 true, 화면 밖에있을때 false )//시작하는 위치 //플래그 변수
    float beeSpeed = 0.f;

    RectangleShape timerBar;
    float timerBarWidth = 400;
    float timerBarHeight = 80;

    Vector2f timerBarSize = Vector2f(timerBarWidth, timerBarHeight);
    timerBar.setSize(timerBarSize);
    Vector2f timerPos = Vector2f(1920 * 0.5f - timerBarWidth * 0.5f, 980.f);
    timerBar.setPosition(timerPos);
    timerBar.setFillColor(Color::Red);

    //가지
    Texture textureBranch;
    textureBranch.loadFromFile("graphics/branch.png");

    const int countBranches = 6;
    Sprite spriteBranches[countBranches];
    side sideBranches[countBranches];
    for (int i = 0; i < countBranches; i++)
    {
        spriteBranches[i].setTexture(textureBranch);
        spriteBranches[i].setPosition(-2000, -2000);
        spriteBranches[i].setOrigin(220, 40);

        sideBranches[i] = side::NONE;
    }

    bool isPause = true; // true : 일시정지 

    int score = 100;
    const float timeMax = 6.0f;
    float timeRemaining = timeMax; //델타타임으로 뺌
    float timerBarWidthPerSecond = timerBarWidth / timeMax;

    // Prepare the player
    Texture texturePlayer;
    texturePlayer.loadFromFile("graphics/player.png");
    Sprite spritePlayer;
    spritePlayer.setTexture(texturePlayer);
    spritePlayer.setPosition(580, 720);
    // The player starts on the left
    side playerSide = side::LEFT;

    // Prepare the gravestone
    Texture textureRIP;
    textureRIP.loadFromFile("graphics/rip.png");
    Sprite spriteRIP;
    spriteRIP.setTexture(textureRIP);
    spriteRIP.setPosition(600, 860);

    // Prepare the axe
    Texture textureAxe;
    textureAxe.loadFromFile("graphics/axe.png");
    Sprite spriteAxe;
    spriteAxe.setTexture(textureAxe);
    spriteAxe.setPosition(700, 830);

    // Line the axe up with the tree
    const float AXE_POSITION_LEFT = 700;
    const float AXE_POSITION_RIGHT = 1075;

    // Prepare the flying log
    Texture textureLog;
    textureLog.loadFromFile("graphics/log.png");
    Sprite spriteLog;
    spriteLog.setTexture(textureLog);
    spriteLog.setPosition(810, 720);

    SoundBuffer chopBuffer;
    chopBuffer.loadFromFile("sound/chop.wav");
    Sound chop;
    chop.setBuffer(chopBuffer);

    SoundBuffer deathBuffer;
    deathBuffer.loadFromFile("sound/death.wav");
    Sound death;
    death.setBuffer(deathBuffer);

    SoundBuffer ootBuffer;
    ootBuffer.loadFromFile("sound/out_of_time.wav");
    Sound oot;
    oot.setBuffer(ootBuffer);


    // Some other useful log related variables
    bool logActive = false; //도끼를 쳤을때 날라가는 토망
    float logSpeedX = 1000;
    float logSpeedY = -1500;

    bool acceptInput = false; //입력 키

    Clock clock;
    Texture textureTree;
    textureTree.loadFromFile("graphics/Tree.png");

    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    while (window.isOpen())
    {




        Time dt = clock.restart();
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                switch (event.key.code)
                {
                case Keyboard::Escape:
                    window.close();
                    break;
                case Keyboard::Return:
                {
                    isPause = false;
                    score = 0;
                    timeRemaining = timeMax;
                    acceptInput = true;

                    for (int i = 0; i < countBranches; ++i)
                    {
                        sideBranches[i] = side::NONE;
                    }
                    spriteRIP.setPosition(675, 2000);
                    spritePlayer.setPosition(580, 720);
                }
                break;
                case Keyboard::Left:
                    if (acceptInput && !isPause)
                    {
                        chop.play();
                        {
                            playerSide = side::LEFT;
                            ++score;

                            timeRemaining += (2.f / score) + 0.15f; //현재 스코어가 커질수록 채워지는 시간이 줄어듬
                            if (timeRemaining > timeMax)
                            {
                                timeRemaining = timeMax;
                            }
                            spriteAxe.setPosition(AXE_POSITION_LEFT, spriteAxe.getPosition().y);

                            spritePlayer.setPosition(580, 720);

                            UpdateBranches(sideBranches, countBranches, gen);

                            spriteLog.setPosition(810, 720);

                            logSpeedX = 5000;
                            logActive = true;

                            acceptInput = false;
                        }
                    }
                    break;
                case Keyboard::Right:
                    if (acceptInput && !isPause)
                    {
                        chop.play();
                        {
                            playerSide = side::RIGHT;
                            ++score;

                            timeRemaining += (2.f / score) + 0.15f; //현재 스코어가 커질수록 채워지는 시간이 줄어듬
                            if (timeRemaining > timeMax)
                            {
                                timeRemaining = timeMax;
                            }
                            spriteAxe.setPosition(AXE_POSITION_RIGHT, spriteAxe.getPosition().y);

                            spritePlayer.setPosition(1200, 720);

                            UpdateBranches(sideBranches, countBranches, gen);

                            spriteLog.setPosition(810, 720);

                            logSpeedX = -5000;
                            logActive = true;

                            acceptInput = false;
                        }
                    }
                    break;
                default:
                    break;
                }
                break;
            case Event::KeyReleased:
                if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Right)
                {
                    if (!isPause)
                    {
                        acceptInput = true;
                        spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
                    }

                }
                break;
            default:
                break;
            }
        }

        /*----------------------------------------------------------------------------*/
        /*----------------------------------------------------------------------------*/

        if (menuOn && Keyboard::isKeyPressed(Keyboard::Up))
        {
            menuIndex--;
            if (menuIndex < 0)
                menuIndex = 0;
            menuBox[menuIndex + 1].setFillColor(Color(252, 241, 207, 255));
            menuBox[menuIndex].setFillColor(Color(180, 180, 80, 255));

        }

        if (menuOn && Keyboard::isKeyPressed(Keyboard::Down))
        {
            menuIndex++;
            if (menuIndex > 3)
                menuIndex = 3;
            menuBox[menuIndex - 1].setFillColor(Color(252, 241, 207, 255));
            menuBox[menuIndex].setFillColor(Color(180, 180, 80, 255));
            ;
        }

        if (menuOn && Keyboard::isKeyPressed(Keyboard::Enter))
        {
            if (menuIndex == 1)
            {
                menuOn = false;
                selModeOn = true;
            }
        }


        if (selModeOn &&  Keyboard::isKeyPressed(Keyboard::Up))
        {
            SelIndex--;
            if (SelIndex < 0)
                SelIndex = 0;
            selGame[SelIndex + 1].setFillColor(Color(252, 241, 207, 255));
            selGame[SelIndex].setFillColor(Color(180, 180, 80, 255));
        }
      
        if (selModeOn && Keyboard::isKeyPressed(Keyboard::Down))
        {
            
            SelIndex++;
            if (SelIndex > 1)
            {
                SelIndex = 1;
            }
            if (SelIndex > 0)
            {
                selGame[SelIndex - 1].setFillColor(Color(252, 241, 207, 255));
            }
            selGame[SelIndex].setFillColor(Color(180, 180, 80, 255));
        }

        if (selModeOn && Keyboard::isKeyPressed(Keyboard::Enter))
        {
          //  selModeOn = false;
        }



        /*----------------------------------------------------------------------------*/
        /*----------------------------------------------------------------------------*/

        // 업데이트

        if (!isPause)
        {
            //벌
            if (!beeActive)
            {
                //벌 초기화
                beeSpeed = gen() % 200 + 200; //속도
                beeSpeed *= -1.f;
                float y = gen() % 500 + 500; //y값
                spriteBee.setPosition(2000, y);
                beeActive = true;
            }
            else
            {
                //벌 이동
                float deltaX = beeSpeed * dt.asSeconds(); //시간을 float형으로 리턴해주는 함수 / 속도 * 시간
                Vector2f currPos = spriteBee.getPosition(); // 벌의 현재 위치 
                currPos.x += deltaX;
                spriteBee.setPosition(currPos);

                //화면 밖으로 나갔는지 테스트
                if (currPos.x < -100)
                {
                    beeActive = false;
                }
            }

            //구름1
            if (!cloudActive)
            {
                clodeSpeed = gen() % 300 + 100;
                clodeSpeed *= -1.f;
                float y = (int)gen() % 100 + 200;
                //float x = (int)gen() % 200 - 400;
                spriteCloud1.setPosition(2000, y);
                cloudActive = true;
            }
            else
            {
                float deltaX = clodeSpeed * dt.asSeconds();
                Vector2f currPos = spriteCloud1.getPosition();
                currPos.x += deltaX;
                spriteCloud1.setPosition(currPos);

                //화면 밖으로 나갔는지 테스트
                if (currPos.x < -100)
                {
                    cloudActive = false;
                }

            }
            //구름2
            if (!cloudActive)
            {
                clodeSpeed = gen() % 300 + 200;
                clodeSpeed *= -1.f;
                float y = gen() % 100 + 60;
                spriteCloud2.setPosition(2000, y);
                cloudActive = true;
            }
            else
            {
                float deltaX = clodeSpeed * dt.asSeconds();
                Vector2f currPos = spriteCloud2.getPosition();
                currPos.x += deltaX;
                spriteCloud2.setPosition(currPos);

                //화면 밖으로 나갔는지 테스트
                if (currPos.x < -100)
                {
                    cloudActive = false;
                }
            }
            //구름3
            if (!cloudActive)
            {
                clodeSpeed = gen() % 300 + 600;
                clodeSpeed *= -1.f;
                float y = gen() % 50 + 50;
                spriteCloud3.setPosition(2000, y);
                cloudActive = true;
            }
            else
            {
                float deltaX = clodeSpeed * dt.asSeconds();
                Vector2f currPos = spriteCloud3.getPosition();
                currPos.x += deltaX;
                spriteCloud3.setPosition(currPos);

                //화면 밖으로 나갔는지 테스트
                if (currPos.x < -100)
                {
                    cloudActive = false;
                }

            }
            stringstream ss;
            ss << "Score = " << score;
            textScore.setString(ss.str());

            timeRemaining -= dt.asSeconds();
            timerBarSize.x = timeRemaining * timerBarWidthPerSecond;
            timerBar.setSize(timerBarSize);
            if (timeRemaining < 0.f)
            {
                timerBarSize.x = 0.f;
                timerBar.setSize(timerBarSize);

                isPause = true;

                textMessage.setString("Out of time!!");

                FloatRect textRect = textMessage.getLocalBounds(); //구조체 - 중앙점 계산
                textMessage.setOrigin
                (
                    textRect.left + textRect.width * 0.5f,
                    textRect.top + textRect.height * 0.5f
                );
                oot.play();
            }
            for (int i = 0; i < countBranches; ++i)
            {
                float height = 150 * i;
                switch (sideBranches[i])
                {
                case side::LEFT:
                    spriteBranches[i].setPosition(610, height);
                    spriteBranches[i].setRotation(180);
                    break;
                case side::RIGHT:
                    spriteBranches[i].setPosition(1330, height);
                    spriteBranches[i].setRotation(0);
                    break;
                default:
                    spriteBranches[i].setPosition(-2000, -2000);
                    spriteBranches[i].setRotation(0);
                    break;
                }
            }

            if (logActive) //이동
            {
                Vector2f logPos = spriteLog.getPosition();
                logPos.x += logSpeedX * dt.asSeconds();
                logPos.y += logSpeedX * dt.asSeconds();
                spriteLog.setPosition(logPos);

                if (logPos.x < -100 || logPos.y > 2000)
                {
                    logActive = false;
                    spriteLog.setPosition(810, 720);
                }
            }
            if (sideBranches[countBranches - 1] == playerSide) //플레이어가 깔려서 죽을때
            {
                isPause = true;
                acceptInput = false;
                spritePlayer.setPosition(2000, 600);
                spriteRIP.setPosition(525, 760);

                textMessage.setString("SQUISHED!");
                FloatRect textRect = textMessage.getLocalBounds(); //구조체 - 중앙점 계산
                textMessage.setOrigin
                (
                    textRect.left + textRect.width * 0.5f,
                    textRect.top + textRect.height * 0.5f
                );
                death.play();
            }
        }
        // 그리기
        //world
        window.clear();
        window.draw(spriteBackground);
   /*     window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);*/

        if (menuOn)
        {
            window.draw(menuBox[0]);
            window.draw(menuBox[1]);
            window.draw(menuBox[2]);
            window.draw(menuBox[3]);


            window.draw(menu[0]);
            window.draw(menu[1]);
            window.draw(menu[2]);
            window.draw(menu[3]);
        }

        if (selModeOn)
        {
            window.draw(selGame[0]);
            window.draw(selGame[1]);
            window.draw(selCh[0]);
            window.draw(selCh[1]);
        }


        //window.draw(spriteTree);
        //for (int i = 0; i < countBranches; i++)
        //{
        //    window.draw(spriteBranches[i]);
        //}
        //window.draw(spritePlayer); // 플레이어
        //window.draw(spriteAxe);
        //window.draw(spriteLog);
        //window.draw(spriteRIP);
        //window.draw(spriteBee);
        // ui

     /*   window.draw(textScore);


          if (isPause)
          {
              window.draw(textMessage);
          }
     
     window.draw(timerBar);*/
        window.display();
    }
    return 0;
}