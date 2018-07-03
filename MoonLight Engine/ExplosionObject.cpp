#include "stdafx.h"
#include "ExplosionObject.h"
#include "DestroyComponent.h"


ExplosionObject::ExplosionObject()
{
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("explosion");

	sprite->SetAnimated(true);
	sprite->SetAnimationParams(8, 4, 50,50, 0, 0);

	AddComponent(new DestroyComponent(0.5f));

	SetScale(2.0f);
}


ExplosionObject::~ExplosionObject()
{
}
