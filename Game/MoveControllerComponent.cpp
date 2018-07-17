#include "stdafx.h"
#include "MoveControllerComponent.h"
#include "../MoonLight Engine/GameObject.h"
#include "../MoonLight Engine/InputManager.h"
#include "../MoonLight Engine/RigidBodyComponent.h"

MoveControllerComponent::MoveControllerComponent()
{
}


MoveControllerComponent::~MoveControllerComponent()
{
}

void MoveControllerComponent::Update(float )
{

	auto input = InputManager::GetInstance();

	auto rigid = m_pGameObject->GetComponent<RigidBodyComponent>();

	float x{}, y{};

	input->GetThumbstickLeft(x, y);
	

	if(input->IsActionTriggered(GameSettings::Input::Right))
	{
		x = 1;
	}
	if (input->IsActionTriggered(GameSettings::Input::Left))
	{
		x = -1;
	}
	if (input->IsActionTriggered(GameSettings::Input::Up))
	{
		y = -1;
	}
	if (input->IsActionTriggered(GameSettings::Input::Down))
	{
		y = 1;
	}

	rigid->SetLinearVelocity(x * m_Speed, y * m_Speed);
}
