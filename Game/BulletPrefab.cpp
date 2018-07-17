#include "stdafx.h"
#include "BulletPrefab.h"

#include "ExplosionObject.h"
#include "../MoonLight Engine/GameScene.h"

#include "../MoonLight Engine/BulletComponent.h"
#include "../MoonLight Engine/DestroyComponent.h"


BulletPrefab::BulletPrefab(const float angle, const float ttl, float speed) :
m_Speed(speed)
{

	auto rigid = new RigidBodyComponent(CollisionGroup::CATEGORY_PLAYER_BULLETS
		, CollisionGroup::MASK_PLAYER_BULLETS
		, true, false, true, 100,100,100);
	AddComponent(rigid);
	auto bulletComp = new BulletComponent(angle, speed);
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

void BulletPrefab::OnDestroy()
{
	auto explosion = new ExplosionObject();
	auto pos = GetPosition();
	explosion->SetPosition(pos.x, pos.y);

	GetScene()->AddChild(explosion);
}

void BulletPrefab::HandleCollision(GameObject* other)
{
	//if (other->GetTag() == "Crate") other->Destroy();
	Destroy();
}
