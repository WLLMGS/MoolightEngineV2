#include "stdafx.h"
#include "../MoonLight Engine/Game.h"
#include "MoonlightGame.h"
#include "vld.h"

int main()
{
	srand(uint16(time(NULL)));

	MoonlightGame game;

	game.Run();

	game.CleanUp();
	return 0;
}
