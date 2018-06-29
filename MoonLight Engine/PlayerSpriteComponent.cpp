#include "stdafx.h"
#include "PlayerSpriteComponent.h"
#include "SpriteComponent.h"
#include "GameObject.h"


PlayerSpriteComponent::PlayerSpriteComponent()
{
	
}


PlayerSpriteComponent::~PlayerSpriteComponent()
{
}

void PlayerSpriteComponent::Update(float )
{
	
	auto mousePos = Mouse::getPosition();

	auto worldMouse = Game::m_pWindow->mapPixelToCoords(mousePos);

	auto pos = m_pGameObject->m_pRectangle->getPosition();

	float angle = Math::CalculateAngle(pos.x, pos.y, float(worldMouse.x), float(worldMouse.y)) * Math::Rad2Deg;


	if (angle > -22.5f && angle < 22.5f)
	{
		m_pSprite->SetTexture("character1Side");
	}
	else if (angle < -22.5f && angle > -67.5f)
	{
		m_pSprite->SetTexture("character1DiagUp");
	}
	else if (angle < -67.5f && angle > -112.5f)
	{
		m_pSprite->SetTexture("character1North");
	}
	else if (angle < -112.5f && angle > -157.5f)
	{
		m_pSprite->SetTexture("character1DiagUpFlipped");
	}
	else if (angle < -157.5f || angle > 157.5f)
	{
		m_pSprite->SetTexture("character1SideFlipped");
	}
	else if (angle < 157.5f && angle > 112.5f)
	{
		m_pSprite->SetTexture("character1DiagDownFlipped");
	}
	else if (angle < 112.5f && angle > 67.5f)
	{
		m_pSprite->SetTexture("character1South");
	}
	else if (angle < 67.5f && angle > 22.5f)
	{
		m_pSprite->SetTexture("character1DiagDown");
	}
}

void PlayerSpriteComponent::Init()
{
	m_pSprite = new SpriteComponent();

	m_pGameObject->AddComponent(m_pSprite);

	m_pSprite->SetTexture("character1Side");
	m_pSprite->SetAnimated(true);
	m_pSprite->SetAnimationParams(8, 4, 19, 24, 0, 0);
}
