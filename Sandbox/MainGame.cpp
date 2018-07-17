#include "../MoonLight Engine/stdafx.h"
#include "MainGame.h"
#include "../MoonLight Engine/SceneManager.h"
#include "../MoonLight Engine/DemoScene.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::Setup()
{
	SceneManager::GetInstance()->AddScene(new DemoScene());
}
