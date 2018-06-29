#include "stdafx.h"
#include "PlayerPrefab.h"
#include "MoveComponent.h"
#include "PlayerSpriteComponent.h"
#include "RigidBodyComponent.h"
PlayerPrefab::PlayerPrefab()
{
	auto sprite = new PlayerSpriteComponent();
	AddComponent(sprite);
	sprite->Init();
	
	AddComponent(new MoveComponent());
	//AddComponent(new ColliderComponent());
	auto rigid = new RigidBodyComponent();
	AddComponent(rigid);

	SetScale(2.0f);
}


PlayerPrefab::~PlayerPrefab()
{
}

void PlayerPrefab::OnCollision(ColliderComponent* other)
{
	(other);
}

