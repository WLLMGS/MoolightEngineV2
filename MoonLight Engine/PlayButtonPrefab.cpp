#include "stdafx.h"
#include "PlayButtonPrefab.h"
#include "ButtonComponent.h"
#include "SceneManager.h"


PlayButtonPrefab::PlayButtonPrefab()
{
	m_pRectangle->setSize({ 342.0f,134.0f });
	m_pRectangle->setOrigin(m_pRectangle->getSize() / 2.0f);

	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("PlayButton");

	auto buttonComp = new ButtonComponent("PlayButton", "PlayButton_hover");
	buttonComp->OnClick([]()
	{
		SceneManager::GetInstance()->NextScene();
	});

	AddComponent(buttonComp);

}


PlayButtonPrefab::~PlayButtonPrefab()
{
}
