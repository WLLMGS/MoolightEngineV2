#pragma once
#include "BaseComponent.h"

class RigidBodyComponent : public BaseComponent
{
public:
	RigidBodyComponent(bool isStatic = false, bool isBox = false,
		float linearDamp = 1.0f
		, float density = 1.0f
	,float friction = 1.0f, float restitution = 1.0f);
	~RigidBodyComponent();
	void Update(float elapsedSec) override;
	void AddForce(float x, float y);
	void SetPosition(float x, float y);
	void SetLinearVelocity(float x, float y);
	void SetScale(float scale);
	WG::Vector2 GetPosition() const;
private:
	b2Body* m_pBody;

private:
	void MakeBody();
	void RemakeBody();
private:
	bool m_IsStatic = false;
	bool m_IsBox = false;
	float m_LinDamp;
	float m_Density;
	float m_Friction;
	float m_Restitution;

	float m_Scale = 1;

};

