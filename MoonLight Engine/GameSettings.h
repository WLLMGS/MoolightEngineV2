#pragma once
namespace GameSettings
{
	const float TILESIZE = 32.0f;

	const int ROOMSIZE = 7;

	enum Input
	{
		Right, Left, Up, Down
	};
}

namespace CollisionGroup
{
	const short CATEGORY_PLAYER = 0x0001;
	const short CATEGORY_ENEMY = 0x0002;
	const short CATEGORY_SCENARY = 0x0004;

	const short MASK_PLAYER = CATEGORY_ENEMY | CATEGORY_SCENARY;
	const short MASK_ENEMY = CATEGORY_PLAYER | CATEGORY_SCENARY | CATEGORY_ENEMY;
	const short MASK_SCENARY = -1;
}