#include "stdafx.h"
#include "PlayerPrefab.h"
#include "PlayerSpriteComponent.h"
#include "RigidBodyComponent.h"
#include "ShootingComponent.h"
#include "MoveControllerComponent.h"

PlayerPrefab::PlayerPrefab()
{
	auto sprite = new PlayerSpriteComponent();
	AddComponent(sprite);
	sprite->Init();
	
	AddComponent(new MoveControllerComponent());
	
	auto rigid = new RigidBodyComponent(CollisionGroup::CATEGORY_PLAYER, CollisionGroup::MASK_PLAYER, true, false, false, 0.01f, 1.0f, 1.0f, 0.1f);
	AddComponent(rigid);

	SetScale(1.75f);

	auto shootingComp = new ShootingComponent();
	AddComponent(shootingComp);


	m_Name = "Player";

}


PlayerPrefab::~PlayerPrefab()
{
}




