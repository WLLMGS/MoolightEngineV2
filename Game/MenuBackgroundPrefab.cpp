#include "stdafx.h"
#include "MenuBackgroundPrefab.h"
#include "../MoonLight Engine/SpriteComponent.h"


MenuBackgroundPrefab::MenuBackgroundPrefab()
{
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("menuBackground");

	SetSize(Game::m_pWindow->getSize().x, Game::m_pWindow->getSize().y);
	SetPosition(Game::m_pWindow->getSize().x / 2.0f, Game::m_pWindow->getSize().y / 2.0f);

}


MenuBackgroundPrefab::~MenuBackgroundPrefab()
{
}
