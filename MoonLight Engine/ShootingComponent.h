#pragma once
#include "GameObject.h"

class ShootingComponent : public BaseComponent
{
public:
	ShootingComponent();
	~ShootingComponent();
	virtual void Update(float elapsedSec) override;

private:
	float m_CD = 0.0f;
private:
	void Shoot(float angle);
};

