#include "stdafx.h"
#include "BaseComponent.h"
#include "GameObject.h"

BaseComponent::BaseComponent()
{
}


BaseComponent::~BaseComponent()
{
}

void BaseComponent::Init()
{
}

void BaseComponent::Update(float elapsedSec)
{
	(elapsedSec);
}

void BaseComponent::Render()
{
}

void BaseComponent::SetGameObject(GameObject* obj)
{
	m_pGameObject = obj;
}
