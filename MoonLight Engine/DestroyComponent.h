#pragma once
#include "BaseComponent.h"

class DestroyComponent : public BaseComponent
{
public:
	DestroyComponent(float cooldown);
	~DestroyComponent();
	virtual void Update(float elapsedSec) override;
private:
	float m_CoolDown;
};

