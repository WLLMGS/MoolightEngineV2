#pragma once
#include "BaseComponent.h"

class RigidBodyComponent : public BaseComponent
{
public:
	RigidBodyComponent();
	~RigidBodyComponent();
	void Update(float elapsedSec) override;
	void AddForce(float x, float y);
	void SetPosition(float x, float y);
	void SetLinearVelocity(float x, float y);
	void SetScale(float scale);
private:
	b2Body* m_pBody;
};

