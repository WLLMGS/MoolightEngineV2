#pragma once
#include "BaseComponent.h"
#include "RigidBodyComponent.h"

class BulletComponent : public BaseComponent
{
public:
	BulletComponent(const float angle);
	~BulletComponent();
	virtual void Update(float elapsedSec) override;
private:
	const float m_Angle;
	const float m_Speed = 20.0f;
	WG::Vector2 m_Velocity;
	RigidBodyComponent* m_pRigid = nullptr;
};

