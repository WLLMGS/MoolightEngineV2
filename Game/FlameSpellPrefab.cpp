#include "stdafx.h"
#include "FlameSpellPrefab.h"

#include "../MoonLight Engine/BulletComponent.h"


FlameSpellPrefab::FlameSpellPrefab(float angle, float speed) :
BulletPrefab(angle, 0.75f, speed)
{
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	//set texture
	
	sprite->SetTexture("flame_bullet");
	sprite->SetAnimated(true);
	sprite->SetAnimationParams(4, 2, 12, 9, 0, 0);

	//auto bc = GetComponent<BulletComponent>();
	//bc->SetSpeed(6.0f);
}


FlameSpellPrefab::~FlameSpellPrefab()
{
}
