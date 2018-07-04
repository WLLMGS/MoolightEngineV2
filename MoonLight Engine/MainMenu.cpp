#include "stdafx.h"
#include "MainMenu.h"
#include "ButtonComponent.h"
#include "SceneManager.h"
#include "MousePrefab.h"
#include "PlayButtonPrefab.h"


MainMenu::MainMenu()
{
	AddChild(new MousePrefab());


	auto playButtonprefab = new PlayButtonPrefab();
	AddUIElement(playButtonprefab);

	playButtonprefab->SetPosition(800.0f, 800.0f);
}


MainMenu::~MainMenu()
{
}

void MainMenu::Update(float )
{
}

void MainMenu::Render()
{
}
