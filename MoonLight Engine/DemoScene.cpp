#include "stdafx.h"
#include "DemoScene.h"
#include "GameObject.h"

#include "ResourceManager.h"
#include "InputManager.h"
#include "MoveComponent.h"
#include "PlayerPrefab.h"
#include "WallPrefab.h"
#include "ColliderComponent.h"

DemoScene::DemoScene()
{
	pPlayer = new PlayerPrefab();

	AddChild(pPlayer);

	InputManager::GetInstance()->AddAction(GameSettings::Input::Up, Keyboard::Z);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Down, Keyboard::S);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Right, Keyboard::D);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Left, Keyboard::Q);

	pWall = new WallPrefab();
	AddChild(pWall);

	pWall->SetPosition(200, 200);
	
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
