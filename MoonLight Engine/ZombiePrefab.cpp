#include "stdafx.h"
#include "ZombiePrefab.h"
#include "RigidBodyComponent.h"
#include "GameScene.h"
#include "ZombieControllerComponent.h"


ZombiePrefab::ZombiePrefab()
{
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("zombie_walk");
	sprite->SetAnimated(true);
	sprite->SetAnimationParams(10, 5, 32, 32, 0, 0);

	auto rigid = new RigidBodyComponent(CollisionGroup::CATEGORY_ENEMY, CollisionGroup::MASK_ENEMY, true, false, false, 1, 1, 1, 1);
	AddComponent(rigid);


	m_pHealthComponent = new HealthComponent(3);

	AddComponent(m_pHealthComponent);
}


ZombiePrefab::~ZombiePrefab()
{
}

void ZombiePrefab::Init()
{
	

	SetScale(2.0f);

	GameObject* player = m_pScene->FindGameObjectByName("Player");

	auto z = new ZombieControllerComponent(player);
	AddComponent(z);

}

void ZombiePrefab::OnCollision(GameObject* other)
{
	if (other->GetTag() == "Bullet")
	{
		m_pHealthComponent->GetHit(1);
	}
}
