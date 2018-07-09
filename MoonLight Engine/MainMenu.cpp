#include "stdafx.h"
#include "MainMenu.h"
#include "ButtonComponent.h"
#include "SceneManager.h"
#include "MousePrefab.h"
#include "PlayButtonPrefab.h"
#include "BackgroundPrefab.h"


MainMenu::MainMenu()
{
	AddChild(new BackgroundPrefab());

	//AddChild(new MousePrefab());

	auto windowSize = Game::m_pWindow->getSize();

	auto playButtonprefab = new PlayButtonPrefab();
	AddUIElement(playButtonprefab);

	playButtonprefab->SetPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);
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
