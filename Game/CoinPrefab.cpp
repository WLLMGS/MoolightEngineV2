#include "stdafx.h"
#include "CoinPrefab.h"
#include "../MoonLight Engine/RigidBodyComponent.h"

CoinPrefab::CoinPrefab()
{
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("coin");
	sprite->SetAnimated(true);
	sprite->SetAnimationParams(12, 6, 16, 16, 0, 0);


	auto rigid = new RigidBodyComponent(CollisionGroup::CATEGORY_LOOT, CollisionGroup::MASK_LOOT, true, false, false);
	AddComponent(rigid);

	SetScale(1.0f);

	m_Tag = "Coin";

}


CoinPrefab::~CoinPrefab()
{
}

void CoinPrefab::Update(float )
{
	
}

