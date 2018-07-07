#pragma once
#include "GameObject.h"

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

