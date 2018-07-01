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
	auto rigid = new RigidBodyComponent(CollisionGroup::CATEGORY_PLAYER, CollisionGroup::MASK_PLAYER, false, false, 0.01f, 1.0f, 1.0f, 0.1f);
	AddComponent(rigid);

	SetScale(1.75f);
}


PlayerPrefab::~PlayerPrefab()
{
}

void PlayerPrefab::LateUpdate()
{

}

void PlayerPrefab::OnCollision(GameObject* other)
{
	m_CollisionEvents.push_back(other);
}

