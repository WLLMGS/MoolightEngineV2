#include "stdafx.h"
#include "SettingsButtonPrefab.h"
#include "../MoonLight Engine/Game.h"
#include "../MoonLight Engine/ButtonComponent.h"
#include "../MoonLight Engine/SceneManager.h"
#include "../MoonLight Engine/TextComponent.h"


SettingsButtonPrefab::SettingsButtonPrefab()
{
	m_pRectangle->setSize({ 342.0f,134.0f });
	m_pRectangle->setOrigin(m_pRectangle->getSize() / 2.0f);

	auto buttonComp = new ButtonComponent();
	buttonComp->OnClick([]()
	{
		SceneManager::GetInstance()->GoToScene("Demo Scene");
	});

	AddComponent(buttonComp);

	AddComponent(new TextComponent("default", "Settings", 50, -80.0f, -32.0f));



	SetPosition(Game::m_pWindow->getSize().x / 2.0f, 900.0f);
}


SettingsButtonPrefab::~SettingsButtonPrefab()
{
}
