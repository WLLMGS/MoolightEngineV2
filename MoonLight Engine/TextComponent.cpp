#include "stdafx.h"
#include "TextComponent.h"
#include "ResourceManager.h"
#include "GameObject.h"


TextComponent::TextComponent(string font, string text, int fontsize, float offsetX, float offsetY) :
m_OffsetX(offsetX),
m_OffsetY(offsetY)
{
	m_Text.setFont(*ResourceManager::GetInstance()->RequestFont(font));
	m_Text.setString(text);
	m_Text.setCharacterSize(fontsize);
}

TextComponent::~TextComponent()
{
} 

void TextComponent::SetText(string text)
{
	m_Text.setString(text);
}

void TextComponent::SetColor(Color& color)
{
	m_Text.setFillColor(color);
}

void TextComponent::Update(float )
{
	auto pos = m_pGameObject->m_pRectangle->getPosition();
	auto size = m_pGameObject->m_pRectangle->getSize();
	
	
	auto worldPos = pos;
	
	worldPos.x += m_OffsetX;
	worldPos.y += m_OffsetY;

	m_Text.setPosition(worldPos.x, worldPos.y);
}

void TextComponent::Render()
{
	Game::m_pWindow->draw(m_Text);
}
