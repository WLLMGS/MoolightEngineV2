#include "stdafx.h"
#include "VerticalWallPrefab.h"
#include "RigidBodyComponent.h"

VerticalWallPrefab::VerticalWallPrefab()
{

	SetSize(64.0f, 384.0f);
	

	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("wall_side");
	sprite->SetTextureRect(0, 0, 16, 96);
	sprite->SetRepeated(true);
	m_Tag = "Wall";

	AddComponent(new RigidBodyComponent(CollisionGroup::CATEGORY_SCENARY, CollisionGroup::MASK_SCENARY, true, true));

	SetScale(1.0f);


	SetPosition(-32.0f, -384 / 2.0f);
}


VerticalWallPrefab::~VerticalWallPrefab()
{
}

void VerticalWallPrefab::SetRoomPos(float x, float y, WallLocation loc)
{
	switch(loc)
	{
	case LeftUp:
		SetPosition(-192.0f + 32.0f + x, 224.0f - 64.f + y);
		break;
	case LeftDown:
		SetPosition(-192.0f + 32.0f + x, 224.0f - 32.0f + y + 384.0f + 64.0f + 32.0f);
		break;
	case RightUp:
		SetPosition(2 * 64.0f + 384.0f + 384.0f / 2.0f + x + 32.0f, 224.0f - 64.f + y);
		break;
	case RightDown:
		SetPosition(2 * 64.0f + 384.0f + 384.0f / 2.0f + x + 32.0f, 224.0f - 32.0f + y + 384.0f + 64.0f + 32.0f);
		break;
	}
}
