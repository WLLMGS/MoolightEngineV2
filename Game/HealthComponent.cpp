#include "stdafx.h"
#include "HealthComponent.h"
#include "../MoonLight Engine/GameObject.h"
HealthComponent::HealthComponent(float hp) :
m_Health(hp)
{
}



void HealthComponent::GetHit(float dmg)
{
	m_Health -= dmg;

	if (m_Health <= 0) m_pGameObject->Destroy();
}

