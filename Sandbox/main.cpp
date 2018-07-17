#include "../MoonLight Engine/Game.h"
#include "MainGame.h"
#include <time.h>

int main(int argc, char* argv[])
{

	srand((time(NULL)));

	MainGame game;

	game.Setup();

	game.Run();

	game.CleanUp();

	return 0;
}
