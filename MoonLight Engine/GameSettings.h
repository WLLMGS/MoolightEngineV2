#pragma once

const bool CONTROLLER = false;

namespace GameSettings
{
	const float TILESIZE = 32.0f;

	const int ROOMSIZE = 7;

	enum Input
	{
		Right, Left, Up, Down, Escape
	};

}

namespace CollisionGroup
{
	const short CATEGORY_PLAYER = 0x0001;
	const short CATEGORY_ENEMY = 0x002;
	const short CATEGORY_SCENARY = 0x0004;
	const short CATEGORY_LOOT = 0x0008;
	const short CATEGORY_PLAYER_BULLETS = 0x0010;


	const short MASK_PLAYER = CATEGORY_ENEMY | CATEGORY_SCENARY | CATEGORY_LOOT;
	const short MASK_ENEMY = CATEGORY_PLAYER | CATEGORY_SCENARY | CATEGORY_ENEMY | CATEGORY_PLAYER_BULLETS;
	const short MASK_LOOT = CATEGORY_PLAYER | CATEGORY_SCENARY;
	const short MASK_PLAYER_BULLETS = CATEGORY_ENEMY | CATEGORY_SCENARY;
	const short MASK_SCENARY = -1;

}