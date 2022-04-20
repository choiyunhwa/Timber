#include "Framework.h"

void Framework::Initialize()
{
	graphics.initializerGraphics();
	sound.InitializeSound();
	Ui.InitializeUI();
	backgrounds.InitializeBackground();
	branches.InitializeBranches();
	player.initializePlayer();
	rip.initializeRIP();
    axe.initializeAxe();
    log.InitializeLog();
    tree.InitializeTree();
}

void Framework::Update()
{
    if (window.isOpen())
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

                    Ui.SetScore(0);
                    Ui.ResetTimeRemaining();
                    acceptInput = true;

                    for (int i = 0; i < branches.GetCountBranches(); i++)
                    {
                        branches.GetSideBranchesArray()[i] = side::NONE;
                    }
                    player.GetSpritePlayer().setPosition(580, 720);
                    rip.GetspriteRIP().setPosition(675, 2000);
                }
                break;
                case Keyboard::Left:
                    if (acceptInput && !isPause)
                    {
                        sound.PlaySound(SoundID::chop);
                        {
                            player.SetSide(side::LEFT);
                            Ui.SetScore(Ui.GetScore() + 1);

                            Ui.SetTimeRemaining(Ui.GetTimeRemaining() + (2.f / Ui.GetScore()) + 0.15f); //현재 스코어가 커질수록 채워지는 시간이 줄어듬
                            if (Ui.GetTimeRemaining() > Ui.GetTimeMax())
                            {
                                Ui.ResetTimeRemaining();
                            }
                            axe.GetSpriteAxe().setPosition(axe.GetAXE_POSITION_LEFT(), axe.GetSpriteAxe().getPosition().y);

                            player.GetSpritePlayer().setPosition(580, 720);

                            branches.UpdateBranches(branches.GetSideBranchesArray(), branches.GetCountBranches(), gen);

                            log.GetSpriteLog().setPosition(810, 720);

                            
                            log.SetLogSpeedX(5000);
                            log.SetLogActive(true); 

                            acceptInput = false;
                        }
                    }
                    break;
                case Keyboard::Right:
                    if (acceptInput && !isPause)
                    {
                        sound.PlaySound(SoundID::chop);
                        {
                            player.SetSide(side::RIGHT);
                            Ui.SetScore(Ui.GetScore() + 1);


                            Ui.SetTimeRemaining(Ui.GetTimeRemaining() + (2.f / Ui.GetScore()) + 0.15f); //현재 스코어가 커질수록 채워지는 시간이 줄어듬
                            if (Ui.GetTimeRemaining() > Ui.GetTimeMax())
                            {
                                Ui.ResetTimeRemaining();
                            }
                            axe.GetSpriteAxe().setPosition(axe.GetAXE_POSITION_RIGHT(), axe.GetSpriteAxe().getPosition().y);

                            player.GetSpritePlayer().setPosition(580, 720);

                            branches.UpdateBranches(branches.GetSideBranchesArray(), branches.GetCountBranches(), gen);

                            log.GetSpriteLog().setPosition(810, 720);


                            log.SetLogSpeedX(-5000);
                            log.SetLogActive(true);

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
                        axe.GetSpriteAxe().setPosition(2000, axe.GetSpriteAxe().getPosition().y);
                    }

                }
                break;
            default:
                break;
            }
        }
        if (!isPause)
        {
            //벌
            if (!backgrounds.moveActivateArray()[3])
            {
                //벌 초기화
                backgrounds.moveSpeedArray()[3] = gen() % 200 + 200; //속도
                backgrounds.moveSpeedArray()[3] *= -1.f;
                float y = gen() % 500 + 500; //y값
                backgrounds.moveObjectArray() [3].setPosition(2000, y);
                backgrounds.moveActivateArray() [3] = true;
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
    }

}
