#include "stdafx.h"
#include "SmokePrefab.h"
#include "../MoonLight Engine/DestroyComponent.h"

SmokePrefab::SmokePrefab()
{
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("smoke");
	sprite->SetAnimated(true);
	sprite->SetAnimationParams(12, 6, 32, 32, 0, 0);

	auto destroy = new DestroyComponent(0.5f);
	AddComponent(destroy);


	SetScale(3.0f);
}


SmokePrefab::~SmokePrefab()
{
}
