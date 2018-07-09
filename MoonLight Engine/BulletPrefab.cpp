#include "stdafx.h"
#include "BulletPrefab.h"
#include "BulletComponent.h"
#include "ExplosionObject.h"
#include "GameScene.h"
#include "DestroyComponent.h"


BulletPrefab::BulletPrefab(const float angle, const float ttl)
{
	auto rigid = new RigidBodyComponent(CollisionGroup::CATEGORY_PLAYER
		, CollisionGroup::MASK_PLAYER
		, true, false, true);
	AddComponent(rigid);
	auto bulletComp = new BulletComponent(angle);
	AddComponent(bulletComp);

	SetScale(1.0f);

	m_pRectangle->setRotation(angle * Math::Rad2Deg);
	
	AddComponent(new DestroyComponent(ttl));

	m_Tag = "Bullet";


	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("bullet_c");

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
