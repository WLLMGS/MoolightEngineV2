#include "stdafx.h"
#include "MoonlightGame.h"
#include "../MoonLight Engine/SceneManager.h"
#include "DemoScene.h"
#include "MainMenu.h"
#include "PauseMenu.h"

MoonlightGame::MoonlightGame()
{
}


MoonlightGame::~MoonlightGame()
{
}

void MoonlightGame::Setup()
{
	SceneManager::GetInstance()->AddScene(new MainMenu());
	SceneManager::GetInstance()->AddScene(new DemoScene());
	SceneManager::GetInstance()->AddScene(new PauseMenu());
}
