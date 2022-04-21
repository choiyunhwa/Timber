#include "Framework.h"

int main()
{
	Framework mainLoop;

	mainLoop.Initialize();

	while (true)
	{
		mainLoop.Update();

		mainLoop.Draw();
	}

	return 0;
}