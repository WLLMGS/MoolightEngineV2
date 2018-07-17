#include "stdafx.h"
#include "MainMenu.h"
#include "../MoonLight Engine/ButtonComponent.h"
#include "../MoonLight Engine/SceneManager.h"
#include "PlayButtonPrefab.h"
#include "BackgroundPrefab.h"
#include "MenuBackgroundPrefab.h"
#include "SettingsButtonPrefab.h"


MainMenu::MainMenu()
{
	m_Name = "Main Menu";
	//AddChild(new BackgroundPrefab());




	/*auto obj = new GameObject();
	AddChild(obj);
	auto sprite = new SpriteComponent();
	obj->AddComponent(sprite);
	sprite->SetTexture("menuBackground");
	obj->SetSize(Game::m_pWindow->getSize().x, Game::m_pWindow->getSize().y);
	obj->SetPosition(Game::m_pWindow->getSize().x / 2.0f, Game::m_pWindow->getSize().y / 2.0f);

*/

	AddChild(new MenuBackgroundPrefab());

	auto obj = new GameObject();
	obj->SetSize(512, 128);
	obj->SetScale(3.0f);
	AddChild(obj);
	auto sprite = new SpriteComponent();
	obj->AddComponent(sprite);
	sprite->SetTexture("title");

	obj->SetPosition(Game::m_pWindow->getSize().x / 2.0f, 350.0f);

	AddUIElement(new PlayButtonPrefab());

	AddUIElement(new SettingsButtonPrefab());
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
