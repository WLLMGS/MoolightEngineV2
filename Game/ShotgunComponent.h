#pragma once
#include "../MoonLight Engine/ShootingComponent.h"

class ShotgunComponent : public ShootingComponent
{
public:
	ShotgunComponent();
	~ShotgunComponent();
	virtual void Shoot(float angle) override;
};

