#include "stdafx.h"
#include "DemoScene.h"
#include "PlayerPrefab.h"
#include <ppltasks.h>
#include "DungeonGenerator.h"
#include "BackgroundPrefab.h"
#include "ZombiePrefab.h"
#include "GameplayManager.h"

DemoScene::DemoScene()
{
	m_Name = "Demo Scene";

	auto bg = new BackgroundPrefab();
	AddChild(bg);
	DungeonGenerator::GenerateDungeon(this, 11, 11);

	pPlayer = new PlayerPrefab();
	
	AddChild(pPlayer);
	pPlayer->SetPosition(DungeonGenerator::GetSpawnPos().x, DungeonGenerator::GetSpawnPos().y);


	m_Camera.Set(pPlayer, { 720.0f,480.0f}, 1.45f);
	
	AddChild(new GameplayManager());
}


DemoScene::~DemoScene()
{
}



