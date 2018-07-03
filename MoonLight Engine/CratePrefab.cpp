#include "stdafx.h"
#include "CratePrefab.h"
#include "RigidBodyComponent.h"

CratePrefab::CratePrefab()
{
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("crate");

	auto rigid = new RigidBodyComponent(
		CollisionGroup::CATEGORY_ENEMY
		, CollisionGroup::MASK_ENEMY
		, false, true, 5, 5, 5, 0
	);

	AddComponent(rigid);

	SetScale(2.0f);

	m_Tag = "Crate";
}


CratePrefab::~CratePrefab()
{
}
