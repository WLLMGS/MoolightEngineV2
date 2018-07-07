#include "stdafx.h"
#include "BackgroundPrefab.h"


BackgroundPrefab::BackgroundPrefab()
{
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("dungeonTiles");
	sprite->SetTextureRect(32, 48, 16, 16);

	SetScale(1000.0f);
}


BackgroundPrefab::~BackgroundPrefab()
{
}
