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

DemoScene::DemoScene()
{
	pPlayer = new PlayerPrefab();

	AddChild(pPlayer);

	pPlayer->SetPosition(300, 500);

	InputManager::GetInstance()->AddAction(GameSettings::Input::Up, Keyboard::Z);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Down, Keyboard::S);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Right, Keyboard::D);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Left, Keyboard::Q);

	m_Camera.Set(pPlayer, { 1280.0f,720.0f}, 1.25f);

	GenerateBuilding();

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
