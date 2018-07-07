#include "stdafx.h"
#include "ButtonComponent.h"
#include "GameObject.h"

ButtonComponent::ButtonComponent(string texNormal, string texHover) :
m_TextureNormal(texNormal),
m_TextureHover(texHover)
{
}


ButtonComponent::~ButtonComponent()
{
}

void ButtonComponent::Update(float elapsedSec)
{
	CheckHover();

	m_Timer -= elapsedSec;


	if(Mouse::isButtonPressed(Mouse::Left) && m_Timer <= 0.0f && m_IsHovering)
	{
		m_Timer = m_Cooldown;
		
		m_OnClick();
	}
}

void ButtonComponent::OnClick(function<void()> func)
{
	m_OnClick = func;
}

void ButtonComponent::SetTextures(string normal, string hover)
{
	m_TextureHover = hover;
	m_TextureNormal = normal;
}

void ButtonComponent::CheckHover()
{
	auto pos = Mouse::getPosition();

	pos.x += int(GameSettings::TILESIZE / 2.0f);
	pos.y += int(GameSettings::TILESIZE / 2.0f);

	auto buttonpos = m_pGameObject->m_pRectangle->getPosition();
	auto buttonsize = m_pGameObject->m_pRectangle->getSize();

	if (   pos.x > buttonpos.x - buttonsize.x / 2.0f
		&& pos.x < buttonpos.x + buttonsize.x / 2.0f
		&& pos.y > buttonpos.y - buttonsize.y / 2.0f
		&& pos.y < buttonpos.y + buttonsize.y / 2.0f)
	{
		if(!m_IsHovering)
		{
			//change texture to hover
			auto sprite = m_pGameObject->GetComponent<SpriteComponent>();
			sprite->SetTexture(m_TextureHover);
		}
		m_IsHovering = true;
	}
	else
	{
		if(m_IsHovering)
		{
			//change texture to non hover
			auto sprite = m_pGameObject->GetComponent<SpriteComponent>();
			sprite->SetTexture(m_TextureNormal);
		}
		m_IsHovering = false;
	}
}
