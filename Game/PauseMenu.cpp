#include "stdafx.h"
#include "PauseMenu.h"
#include "MenuBackgroundPrefab.h"
#include "PlayButtonPrefab.h"
#include "../MoonLight Engine/InputManager.h"
#include "../MoonLight Engine/SceneManager.h"
#include "ContinueButtonPrefab.h"


PauseMenu::PauseMenu()
{
	m_Camera.SetEnabled(false);

	m_Name = "Pause Menu";
	AddChild(new MenuBackgroundPrefab());

	//play button
	AddUIElement(new ContinueButtonPrefab());

	auto obj = new GameObject();
	obj->SetSize(512, 128);
	obj->SetScale(3.0f);
	AddChild(obj);
	auto sprite = new SpriteComponent();
	obj->AddComponent(sprite);
	sprite->SetTexture("title");

	obj->SetPosition(Game::m_pWindow->getSize().x / 2.0f, 350.0f);
}


PauseMenu::~PauseMenu()
{
}

void PauseMenu::Update(float )
{
	auto input = InputManager::GetInstance();

	//if (input->IsActionTriggered(GameSettings::Input::Escape)) SceneManager::GetInstance()->GoToScene("Demo Scene");
}
