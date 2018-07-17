#include "stdafx.h"
#include "PlayerPrefab.h"
#include "../MoonLight Engine/PlayerSpriteComponent.h"
#include "../MoonLight Engine/RigidBodyComponent.h"
#include "../MoonLight Engine/ShootingComponent.h"
#include "MoveControllerComponent.h"
#include "../MoonLight Engine/ShootingComponent.h"
#include "HealthComponent.h"
#include "ShotgunComponent.h"

PlayerPrefab::PlayerPrefab()
{
	m_pRectangle->setSize({ 76, 96 });

	auto sprite = new PlayerSpriteComponent();
	AddComponent(sprite);
	sprite->Init();
	
	AddComponent(new MoveControllerComponent());
	
	auto rigid = new RigidBodyComponent(CollisionGroup::CATEGORY_PLAYER, CollisionGroup::MASK_PLAYER, true, false, false, 0.01f, 1.0f, 1.0f, 0.1f);
	AddComponent(rigid);

	SetScale(1.75f);

	auto shootingComp = new ShotgunComponent();
	AddComponent(shootingComp);

	AddComponent(new HealthComponent(2));

	m_Name = "Player";
}


PlayerPrefab::~PlayerPrefab()
{
	
}

void PlayerPrefab::HandleCollision(GameObject* other)
{
	if(other->GetTag() == "Coin")
	{
		other->Destroy();
	}
}




