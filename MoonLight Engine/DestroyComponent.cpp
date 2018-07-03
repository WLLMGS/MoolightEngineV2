#include "stdafx.h"
#include "DestroyComponent.h"
#include "GameObject.h"

DestroyComponent::DestroyComponent(float cooldown) : 
m_CoolDown(cooldown)
{
}


DestroyComponent::~DestroyComponent()
{
}

void DestroyComponent::Update(float elapsedSec)
{
	m_CoolDown -= elapsedSec;

	if (m_CoolDown <= 0.0f) m_pGameObject->Destroy();
}
