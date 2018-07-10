#include "stdafx.h"
#include "PlayerSpriteComponent.h"
#include "SpriteComponent.h"
#include "GameObject.h"
#include "InputManager.h"


PlayerSpriteComponent::PlayerSpriteComponent()
{
	
}


PlayerSpriteComponent::~PlayerSpriteComponent()
{
}

void PlayerSpriteComponent::Update(float )
{
	
	;


	if(CONTROLLER)
	{
		float x{}, y{};

		auto input = InputManager::GetInstance();
		input->GetThumbstickRight(x, y);
		if (x != 0 || y != 0) m_Angle = Math::CalculateAngle(x, y) * Math::Rad2Deg;
	}
	else
	{
		auto mousePos = Mouse::getPosition();

		auto worldMouse = Game::m_pWindow->mapPixelToCoords(mousePos);

		auto pos = m_pGameObject->m_pRectangle->getPosition();

		m_Angle = Math::CalculateAngle(pos.x, pos.y, float(worldMouse.x), float(worldMouse.y)) * Math::Rad2Deg;
	}

	
	if (m_Angle > -22.5f && m_Angle < 22.5f)
	{
		m_pSprite->SetTexture("character1Side");
	}
	else if (m_Angle < -22.5f && m_Angle > -67.5f)
	{
		m_pSprite->SetTexture("character1DiagUp");
	}
	else if (m_Angle < -67.5f && m_Angle > -112.5f)
	{
		m_pSprite->SetTexture("character1North");
	}
	else if (m_Angle < -112.5f && m_Angle > -157.5f)
	{
		m_pSprite->SetTexture("character1DiagUpFlipped");
	}
	else if (m_Angle < -157.5f || m_Angle > 157.5f)
	{
		m_pSprite->SetTexture("character1SideFlipped");
	}
	else if (m_Angle < 157.5f && m_Angle > 112.5f)
	{
		m_pSprite->SetTexture("character1DiagDownFlipped");
	}
	else if (m_Angle < 112.5f && m_Angle > 67.5f)
	{
		m_pSprite->SetTexture("character1South");
	}
	else if (m_Angle < 67.5f && m_Angle > 22.5f)
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
