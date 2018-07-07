#include "stdafx.h"
#include "PlayerPrefab.h"
#include "MoveComponent.h"
#include "PlayerSpriteComponent.h"
#include "RigidBodyComponent.h"
#include "ShootingComponent.h"

PlayerPrefab::PlayerPrefab()
{
	auto sprite = new PlayerSpriteComponent();
	AddComponent(sprite);
	sprite->Init();
	
	
	AddComponent(new MoveComponent());
	//AddComponent(new ColliderComponent());
	auto rigid = new RigidBodyComponent(CollisionGroup::CATEGORY_PLAYER, CollisionGroup::MASK_PLAYER, false, false, 0.01f, 1.0f, 1.0f, 0.1f);
	AddComponent(rigid);

	SetScale(1.75f);

	
	auto shootingComp = new ShootingComponent();
	AddComponent(shootingComp);

}


PlayerPrefab::~PlayerPrefab()
{
}




