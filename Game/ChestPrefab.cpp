#include "stdafx.h"
#include "ChestPrefab.h"
#include "../MoonLight Engine/RigidBodyComponent.h"

ChestPrefab::ChestPrefab()
{

	SetSize(32, 16);

	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("chest");
	sprite->SetTextureRect(0,16,32,16);


	auto rigid = new RigidBodyComponent(CollisionGroup::CATEGORY_LOOT, CollisionGroup::MASK_LOOT,false , true, true);
	AddComponent(rigid);
	SetScale(3.0f);
}


ChestPrefab::~ChestPrefab()
{
}
