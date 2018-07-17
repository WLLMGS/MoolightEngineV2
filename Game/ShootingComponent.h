#pragma once
#include "../MoonLight Engine/GameObject.h"

class ShootingComponent : public BaseComponent
{
public:
	ShootingComponent(const float cooldown = 0.25f);
	~ShootingComponent();
	virtual void Update(float elapsedSec) override;

private:
	float m_Timer = 0.0f;
	float m_Cooldown;
private:
	virtual void Shoot(float angle);
	
};

