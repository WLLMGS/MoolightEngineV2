#include "stdafx.h"
#include "BackgroundPrefab.h"


BackgroundPrefab::BackgroundPrefab()
{
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("dungeonTiles");
	sprite->SetTextureRect(64, 96, 16, 16);

	SetScale(1000.0f);
}


BackgroundPrefab::~BackgroundPrefab()
{
}
