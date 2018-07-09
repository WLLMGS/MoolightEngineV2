#include "stdafx.h"
#include "HealthComponent.h"
#include "GameObject.h"
HealthComponent::HealthComponent(int hp) :
m_Health(hp)
{
}



void HealthComponent::GetHit(int dmg)
{
	m_Health -= dmg;

	if (m_Health == 0) m_pGameObject->Destroy();
}

