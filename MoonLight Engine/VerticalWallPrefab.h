#pragma once
#include "GameObject.h"

enum WallLocation
{
	LeftUp,
	LeftDown,
	RightUp,
	RightDown
};

class VerticalWallPrefab : public GameObject
{
public:
	VerticalWallPrefab();
	~VerticalWallPrefab();

	void SetRoomPos(float x, float y, WallLocation loc);
};

