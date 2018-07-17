#include "stdafx.h"
#include "PlayButtonPrefab.h"
#include "../MoonLight Engine/ButtonComponent.h"
#include "../MoonLight Engine/SceneManager.h"
#include "../MoonLight Engine/TextComponent.h"


PlayButtonPrefab::PlayButtonPrefab()
{
	m_pRectangle->setSize({ 342.0f,134.0f });
	m_pRectangle->setOrigin(m_pRectangle->getSize() / 2.0f);

	auto buttonComp = new ButtonComponent();
	buttonComp->OnClick([]()
	{
		SceneManager::GetInstance()->GoToScene("Demo Scene");
	});

	AddComponent(buttonComp);

	AddComponent(new TextComponent("default", "Play", 50, -32.0f,-32.0f));



	SetPosition(Game::m_pWindow->getSize().x / 2.0f, 750.0f);
}


PlayButtonPrefab::~PlayButtonPrefab()
{
}
