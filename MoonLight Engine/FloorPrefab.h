#pragma once
#include "GameObject.h"

class FloorPrefab : public GameObject
{
public:
	FloorPrefab(float x, float y, float width, float height);
	~FloorPrefab();
};
