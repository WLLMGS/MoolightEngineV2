#pragma once
#include "BulletPrefab.h"

class FlameSpellPrefab : public BulletPrefab
{
public:
	FlameSpellPrefab(float angle, float speed = 20.0f);
	~FlameSpellPrefab();
};

