#include "stdafx.h"
#include "Game.h"
#include <vld.h>
#include <time.h>


int main()
{
	srand(uint16(time(NULL)));

	Game game;

	game.Run();

	game.CleanUp();

	return 0;
}