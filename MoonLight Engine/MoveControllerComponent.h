#pragma once
#include "BaseComponent.h"

class MoveControllerComponent : public BaseComponent
{
public:
	MoveControllerComponent();
	~MoveControllerComponent();
	virtual void Update(float elapsedSec) override;

private:
	const float m_Speed = 200.0f;
};

