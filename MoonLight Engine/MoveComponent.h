#pragma once
#include "BaseComponent.h"

class MoveComponent : public BaseComponent
{
public:
	MoveComponent();
	~MoveComponent();
	virtual void Update(float elapsedSec) override;
private:
	float m_X, m_Y;
	float m_Speed = 350.0f;
};

