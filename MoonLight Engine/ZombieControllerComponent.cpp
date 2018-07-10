#include "stdafx.h"
#include "ZombieControllerComponent.h"
#include "GameObject.h"
#include "RigidBodyComponent.h"

ZombieControllerComponent::ZombieControllerComponent(GameObject* player) :
m_pPlayer(player)
{

}


ZombieControllerComponent::~ZombieControllerComponent()
{
}

void ZombieControllerComponent::Update(float)
{
	auto playerpos = m_pPlayer->GetPosition();
	auto pos = m_pGameObject->GetPosition();


	auto dx = abs(playerpos.x - pos.x);
	auto dy = abs(playerpos.y - pos.y);


	if(dx < 500.0f && dy < 500.0f)
	{
		float x{}, y{};

		if (playerpos.x > pos.x) x = m_Speed;
		else x = -m_Speed;

		if (playerpos.y > pos.y) y = m_Speed;
		else y = -m_Speed;

		auto rigid = m_pGameObject->GetComponent<RigidBodyComponent>();
		rigid->SetLinearVelocity(x, y);
	}

	
	
}
