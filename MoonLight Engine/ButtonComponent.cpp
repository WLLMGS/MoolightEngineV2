#include "stdafx.h"
#include "ButtonComponent.h"
#include "GameObject.h"

ButtonComponent::ButtonComponent() 
{
}


ButtonComponent::~ButtonComponent()
{
}

void ButtonComponent::Update(float elapsedSec)
{
	m_Timer -= elapsedSec;

	if(Mouse::isButtonPressed(Mouse::Left) && m_Timer <= 0.0f)
	{
		m_Timer = m_Cooldown;
		auto pos = Mouse::getPosition();

		pos.x += int(GameSettings::TILESIZE / 2.0f);
		pos.y += int(GameSettings::TILESIZE / 2.0f);

		auto buttonpos = m_pGameObject->m_pRectangle->getPosition();
		auto buttonsize = m_pGameObject->m_pRectangle->getSize();

		if(pos.x > buttonpos.x - buttonsize.x / 2.0f
			&& pos.x < buttonpos.x + buttonsize.x / 2.0f
			&& pos.y > buttonpos.y - buttonsize.y / 2.0f
			&& pos.y < buttonpos.y + buttonsize.y / 2.0f)
		{
			m_OnClick();
		}
	}
}

void ButtonComponent::OnClick(function<void()> func)
{
	m_OnClick = func;
}
