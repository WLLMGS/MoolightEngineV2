#include "stdafx.h"
#include "Game.h"
#include <vld.h>
#include <time.h>


int main()
{
	srand(uint16(time(NULL)));

	Game game;

	game.Run();

	return 0;
}