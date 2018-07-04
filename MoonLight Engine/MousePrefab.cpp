#include "stdafx.h"
#include "MousePrefab.h"


MousePrefab::MousePrefab()
{
	auto sprite = new SpriteComponent();
	AddComponent(sprite);
	sprite->SetTexture("crosshair");

	Game::m_pWindow->setMouseCursorVisible(false);
}


MousePrefab::~MousePrefab()
{
}

void MousePrefab::Update(float )
{
	auto pos = Game::m_pWindow->mapPixelToCoords(Mouse::getPosition());

	m_pRectangle->setPosition(pos);
}
