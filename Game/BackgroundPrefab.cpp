#include "stdafx.h"
#include "BackgroundPrefab.h"


BackgroundPrefab::BackgroundPrefab()
{
	m_pRectangle->setSize({ 12800,12800.0f });
	m_pRectangle->setOrigin(6400, 6400);
	m_pRectangle->setPosition(32, 32);
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	//sprite->SetTexture("dungeonTiles");
	sprite->SetTexture("wall_top");
	sprite->SetRepeated(true);
	sprite->SetTextureRect(0, 0, 6400, 6400);

	
}


BackgroundPrefab::~BackgroundPrefab()
{
}
