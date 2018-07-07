#include "stdafx.h"
#include "DemoScene.h"
#include "GameObject.h"

#include "ResourceManager.h"
#include "InputManager.h"
#include "MoveComponent.h"
#include "PlayerPrefab.h"
#include "WallPrefab.h"
#include "ColliderComponent.h"
#include "CratePrefab.h"
#include "SpriteComponent.h"
#include "ButtonComponent.h"
#include "MousePrefab.h"
#include <ppltasks.h>
#include "RoomGenerator.h"
#include "DungeonGenerator.h"
#include "BackgroundPrefab.h"
#include "HorizontalWallPrefab.h"
#include "VerticalWallPrefab.h"

DemoScene::DemoScene()
{

	auto bg = new BackgroundPrefab();
	AddChild(bg);

	

	

	InputManager::GetInstance()->AddAction(GameSettings::Input::Up, Keyboard::Z);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Down, Keyboard::S);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Right, Keyboard::D);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Left, Keyboard::Q);

	


	

	
	DungeonGenerator::GenerateDungeon(this, 7, 7);



	pPlayer = new PlayerPrefab();
	
	AddChild(pPlayer);
	pPlayer->SetPosition(DungeonGenerator::GetSpawnPos().x, DungeonGenerator::GetSpawnPos().y);


	m_Camera.Set(pPlayer, { 1280.0f,720.0f }, 1.25f);


	auto mouse = new MousePrefab();
	AddChild(mouse);
}


DemoScene::~DemoScene()
{
}

void DemoScene::Update(float elapsedSec)
{
	(elapsedSec);

}

void DemoScene::Render()
{
	
}

void DemoScene::GenerateBuilding()
{
	float startX = 500.0f;
	float startY = 300.0f;


	for (int i{}; i < 10; ++i)
	{
		auto crate = new CratePrefab();
		int x = rand() % (16 * int(GameSettings::TILESIZE)) + int(startX);
		int y = rand() % (16 * int(GameSettings::TILESIZE)) + int(startY);
		crate->SetPosition(float(x), float(y));
		AddChild(crate);
	}


	//create room
	for (int i{}; i < 16; ++i)
	{
		auto wall = new WallPrefab();
		AddChild(wall);

		wall->SetPosition(startX + i * GameSettings::TILESIZE * 2.0f, startY);

		wall = new WallPrefab();

		AddChild(wall);
		wall->SetPosition(startX + i * GameSettings::TILESIZE * 2.0f, startY + 16 * GameSettings::TILESIZE * 2.0f - GameSettings::TILESIZE * 2.0f);
	}


	for (int i{}; i < 16; ++i)
	{
		if (i < 6 || i > 8)
		{
			auto wall = new WallPrefab();
			AddChild(wall);

			wall->SetPosition(startX, startY + i * GameSettings::TILESIZE * 2.0f);

			wall = new WallPrefab();

			AddChild(wall);
			wall->SetPosition(startX + 16 * GameSettings::TILESIZE * 2.0f, startY + i * GameSettings::TILESIZE * 2.0f);

		}
	}
}
