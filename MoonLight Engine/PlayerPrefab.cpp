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
	auto rigid = new RigidBodyComponent(false, false, 0.01f,1,1,0.1);
	AddComponent(rigid);

	SetScale(1.75f);
}


PlayerPrefab::~PlayerPrefab()
{
}

void PlayerPrefab::OnCollision(GameObject* other)
{
	if(other->GetTag() == "Wall") cout << "colliding with wall\n";
}

