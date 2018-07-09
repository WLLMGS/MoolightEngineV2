#pragma once
#include "BaseComponent.h"

class HealthComponent : public BaseComponent
{
public:
	HealthComponent(int hp);
	~HealthComponent() = default;
	void GetHit(int dmg);
private:
	int m_Health;
};

