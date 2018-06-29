#include "stdafx.h"
#include "MoveComponent.h"
#include "InputManager.h"
#include "GameObject.h"
#include "RigidBodyComponent.h"

MoveComponent::MoveComponent() :
m_X(0.0f),
m_Y(0.0f)
{
}


MoveComponent::~MoveComponent()
{
}

void MoveComponent::Update(float elapsedSec)
{
	auto input = InputManager::GetInstance();

	auto rigid = m_pGameObject->GetComponent<RigidBodyComponent>();

	m_X = 0.0f;
	m_Y = 0.0f;

	if(input->IsActionTriggered(GameSettings::Input::Right))
	{
		m_X = m_Speed;
	}
	if (input->IsActionTriggered(GameSettings::Input::Left))
	{
		m_X = -m_Speed;
	}
	if (input->IsActionTriggered(GameSettings::Input::Up))
	{
		m_Y = -m_Speed;
	}
	if (input->IsActionTriggered(GameSettings::Input::Down))
	{
		m_Y = m_Speed;
	}

	rigid->SetLinearVelocity(m_X, m_Y);
}
