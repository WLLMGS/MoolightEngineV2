#include "stdafx.h"
#include "ShotgunComponent.h"
#include "../MoonLight Engine/GameScene.h"
#include "BulletPrefab.h"
#include "FlameSpellPrefab.h"

ShotgunComponent::ShotgunComponent() :
ShootingComponent(0.5f)
{
}


ShotgunComponent::~ShotgunComponent()
{
}

void ShotgunComponent::Shoot(float angle)
{
	int range = 20;


	auto worldPos = m_pGameObject->GetPosition();


	for (int i{}; i < 12; ++i)
	{
		int r = rand() % range - (range / 2);
		int speed = rand() % 20 + 10;

		float aOff = r * Math::Deg2Rad;

		auto bullet = new BulletPrefab(angle + aOff,0.5f, float(speed));

		bullet->SetPosition(worldPos.x, worldPos.y);
		m_pGameObject->GetScene()->AddChild(bullet);
	}
}
