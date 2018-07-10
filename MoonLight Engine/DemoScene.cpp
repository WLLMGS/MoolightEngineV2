#include "stdafx.h"
#include "DemoScene.h"
#include "GameObject.h"

#include "InputManager.h"
#include "MoveComponent.h"
#include "PlayerPrefab.h"
#include "WallPrefab.h"
#include "CratePrefab.h"
#include <ppltasks.h>
#include "DungeonGenerator.h"
#include "BackgroundPrefab.h"
#include "ZombiePrefab.h"

DemoScene::DemoScene()
{

	auto bg = new BackgroundPrefab();
	AddChild(bg);


	InputManager::GetInstance()->AddAction(GameSettings::Input::Up, Keyboard::Z);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Down, Keyboard::S);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Right, Keyboard::D);
	InputManager::GetInstance()->AddAction(GameSettings::Input::Left, Keyboard::Q);


	DungeonGenerator::GenerateDungeon(this, 11, 11);

	pPlayer = new PlayerPrefab();
	
	AddChild(pPlayer);
	pPlayer->SetPosition(DungeonGenerator::GetSpawnPos().x, DungeonGenerator::GetSpawnPos().y);


	m_Camera.Set(pPlayer, { 720.0f,480.0f}, 1.45f);

}


DemoScene::~DemoScene()
{
}



