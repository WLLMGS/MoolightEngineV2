#pragma once
#include "../MoonLight Engine/BaseComponent.h"

class HealthComponent : public BaseComponent
{
public:
	HealthComponent(float hp);
	~HealthComponent() = default;
	void GetHit(float dmg);
private:
	float m_Health;
};

