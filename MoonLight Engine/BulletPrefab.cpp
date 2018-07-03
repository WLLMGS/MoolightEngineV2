#include "stdafx.h"
#include "BulletPrefab.h"
#include "BulletComponent.h"
#include "ExplosionObject.h"
#include "GameScene.h"


BulletPrefab::BulletPrefab(const float angle)
{
	auto rigid = new RigidBodyComponent(CollisionGroup::CATEGORY_PLAYER
		, CollisionGroup::MASK_PLAYER
		, false, true);
	AddComponent(rigid);
	(angle);
	auto bulletComp = new BulletComponent(angle);
	AddComponent(bulletComp);

	SetScale(1.0f);


	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("bullet_c");


	m_pRectangle->setRotation(angle * Math::Rad2Deg);

}


BulletPrefab::~BulletPrefab()
{
}

void BulletPrefab::HandleCollision(GameObject* other)
{
	if (other->GetTag() == "Crate") other->Destroy();
	Destroy();
	auto explosion = new ExplosionObject();
	auto pos = GetPosition();
	explosion->SetPosition(pos.x, pos.y);

	GetScene()->AddChild(explosion);
}
