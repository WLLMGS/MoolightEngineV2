#include "stdafx.h"
#include "ZombiePrefab.h"
#include "../MoonLight Engine/RigidBodyComponent.h"
#include "../MoonLight Engine/GameScene.h"
#include "ZombieControllerComponent.h"
#include "CoinPrefab.h"
#include "SmokePrefab.h"


ZombiePrefab::ZombiePrefab()
{
	m_pRectangle->setFillColor({ 255,0,0,255 });

	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("zombie_walk");
	sprite->SetAnimated(true);
	sprite->SetAnimationParams(10, 5, 32, 32, 0, 0);

	auto rigid = new RigidBodyComponent(CollisionGroup::CATEGORY_ENEMY, CollisionGroup::MASK_ENEMY, true, false, false);
	AddComponent(rigid);


	m_pHealthComponent = new HealthComponent(10);

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

void ZombiePrefab::HandleCollision(GameObject* other)
{
	if (other->GetTag() == "Bullet")
	{
		m_pHealthComponent->GetHit(1.0f);
	}
}

void ZombiePrefab::OnDestroy()
{
	auto pos = GetPosition();
	
	for(int i{}; i < 5;++i)
	{
		auto coin = new CoinPrefab();
	
		int rx = rand() % 64 - 32;
		int ry = rand() % 64 - 32;


		coin->SetPosition(pos.x + rx, pos.y + ry);
		GetScene()->AddChild(coin);
	}
	auto smoke = new SmokePrefab();
	smoke->SetPosition(GetPosition().x, GetPosition().y);
	GetScene()->AddChild(smoke);

}
