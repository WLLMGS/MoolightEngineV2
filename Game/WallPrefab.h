#pragma once

#include "../MoonLight Engine/GameObject.h"

enum WallDirection
{
	Top, Bottom, Left, Right
};

class WallPrefab : public GameObject
{
public:
	WallPrefab(WallDirection dir = Top);
	~WallPrefab();
};

