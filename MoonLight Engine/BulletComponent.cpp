#include "stdafx.h"
#include "GameObject.h"
#include "RigidBodyComponent.h"
#include "BulletComponent.h"

BulletComponent::BulletComponent(const float angle, const float speed):
m_Angle(angle),
m_Speed(speed)
{
	m_Velocity.x = cosf(angle) * Math::Rad2Deg * speed;
	m_Velocity.y = sinf(angle) * Math::Rad2Deg * speed;
}


BulletComponent::~BulletComponent()
{
}

void BulletComponent::Update(float )
{
	m_pRigid = m_pGameObject->GetComponent<RigidBodyComponent>();
	m_pRigid->SetLinearVelocity(m_Velocity.x, m_Velocity.y);
}

void BulletComponent::SetSpeed(float speed)
{
	m_Speed = speed;
	m_Velocity.x = cosf(m_Angle) * Math::Rad2Deg * m_Speed;
	m_Velocity.y = sinf(m_Angle) * Math::Rad2Deg * m_Speed;
}
