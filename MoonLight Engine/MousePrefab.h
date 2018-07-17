#pragma once
#include "../MoonLight Engine/GameObject.h"

class MousePrefab : public GameObject
{
public:
	MousePrefab();
	~MousePrefab();
	virtual void Update(float elapsedSec) override;
};

