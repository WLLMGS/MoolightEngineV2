#include "stdafx.h"
#include "HorizontalWallPrefab.h"
#include "../MoonLight Engine/RigidBodyComponent.h"


HorizontalWallPrefab::HorizontalWallPrefab()
{
	SetSize(384.0f, 64.0f);


	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("wall_top");
	sprite->SetTextureRect(0, 0, 96, 16);
	sprite->SetRepeated(true);
	m_Tag = "Wall";

	AddComponent(new RigidBodyComponent(CollisionGroup::CATEGORY_SCENARY, CollisionGroup::MASK_SCENARY, true, true));


	SetScale(1.0f);
}


HorizontalWallPrefab::~HorizontalWallPrefab()
{
}
