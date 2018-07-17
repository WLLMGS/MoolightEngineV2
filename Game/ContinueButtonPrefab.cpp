#include "stdafx.h"
#include "ContinueButtonPrefab.h"
#include "../MoonLight Engine/ButtonComponent.h"
#include "../MoonLight Engine/GameObject.h"
#include "../MoonLight Engine/SceneManager.h"
#include "../MoonLight Engine/TextComponent.h"

ContinueButtonPrefab::ContinueButtonPrefab()
{
	m_pRectangle->setSize({ 342.0f,134.0f });
	m_pRectangle->setOrigin(m_pRectangle->getSize() / 2.0f);

	auto buttonComp = new ButtonComponent();
	buttonComp->OnClick([]()
	{
		SceneManager::GetInstance()->GoToScene("Demo Scene");
	});

	AddComponent(buttonComp);

	AddComponent(new TextComponent("default", "Continue", 50, -80.0f, -32.0f));



	SetPosition(Game::m_pWindow->getSize().x / 2.0f, 750.0f);
}


ContinueButtonPrefab::~ContinueButtonPrefab()
{
}
