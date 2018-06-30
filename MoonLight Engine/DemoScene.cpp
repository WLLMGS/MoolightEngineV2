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

DemoScene::DemoScene()
{
	pPlayer = new PlayerPrefab();

	AddChild(pPlayer);

	pPlayer->SetPosition(300, 500);

	InputManager::GetInstance()->AddAction(GameSettings::Input::Up, Keyboard::Z);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Down, Keyboard::S);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Right, Keyboard::D);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Left, Keyboard::Q);

	m_Camera.Set(pPlayer, { 1920.0f,1080.0f}, 1.0f);


	for(int i{}; i < 10;++i)
	{
		auto crate = new CratePrefab();
		int x = rand() % 700;
		int y = rand() % 500;
		crate->SetPosition(float(x), float(y));
		AddChild(crate);
	}


	float startX = 500.0f;
	float startY = 300.0f;


	//create room
	for(int i{}; i < 16; ++i)
	{
		auto wall = new WallPrefab();
		AddChild(wall);
		
		wall->SetPosition(startX + i * GameSettings::TILESIZE * 2.0f, startY);

		wall = new WallPrefab();

		AddChild(wall);
		wall->SetPosition(startX + i * GameSettings::TILESIZE * 2.0f, startY + 16 * GameSettings::TILESIZE * 2.0f + GameSettings::TILESIZE * 2.0f);
	}


	for (int i{}; i < 16; ++i)
	{
		if(i != 8)
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
