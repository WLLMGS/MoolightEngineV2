#include "stdafx.h"
#include "WallPrefab.h"
#include "RigidBodyComponent.h"


WallPrefab::WallPrefab()
{
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("dungeonTiles");
	sprite->SetTextureRect(0, 16, 16, 16);

	m_Tag = "Wall";

	AddComponent(new RigidBodyComponent(CollisionGroup::CATEGORY_SCENARY, CollisionGroup::MASK_SCENARY,true, true));


	SetScale(2.0f);
}


WallPrefab::~WallPrefab()
{
}
