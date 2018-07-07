#include "stdafx.h"
#include "FloorPrefab.h"


FloorPrefab::FloorPrefab(float x, float y, float width, float height)
{
	m_pRectangle->setPosition(x, y);
	m_pRectangle->setSize({ width, height });


	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("floor_wood");
	sprite->SetRepeated(true);
	sprite->SetTextureRect(0, 0, int(width) / 2 ,int( height)  / 2);
}

FloorPrefab::~FloorPrefab()
{
}
