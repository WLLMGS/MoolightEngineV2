#pragma once
#include "BaseComponent.h"
#include "RigidBodyComponent.h"

class BulletComponent : public BaseComponent
{
public:
	BulletComponent(const float angle, const float speed = 20.0f);
	~BulletComponent();
	virtual void Update(float elapsedSec) override;
	void SetSpeed(float speed);
private:
	const float m_Angle;
	float m_Speed = 20.0f;
	WG::Vector2 m_Velocity;
	RigidBodyComponent* m_pRigid = nullptr;
};

