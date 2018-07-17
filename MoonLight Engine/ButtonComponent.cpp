#include "stdafx.h"
#include "ButtonComponent.h"
#include "GameObject.h"
#include "ResourceManager.h"

ButtonComponent::ButtonComponent() :
m_ColorNormal(0,0,0,127),
m_ColorHover(0,0,0,200)
{
}


ButtonComponent::~ButtonComponent()
{
}

void ButtonComponent::Init()
{	
	m_pGameObject->m_pRectangle->setFillColor(m_ColorNormal);
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
			m_pGameObject->m_pRectangle->setFillColor(m_ColorHover);
		}
		m_IsHovering = true;
	}
	else
	{
		if(m_IsHovering)
		{
			m_pGameObject->m_pRectangle->setFillColor(m_ColorNormal);
		}
		m_IsHovering = false;
	}

	
}
