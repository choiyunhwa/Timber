#include "Framework.h"

void Framework::Initialize()
{
	graphics.initializerGraphics();
	sound.InitializeSound();
	Ui.InitializeUI();
	backgrounds.InitializeBackground();
	branches.InitializeBranches();
	player.initializePlayer();
}

void Framework::Update()
{
	if(window.isOpen())
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
				}
				break;

		}

	}
}
