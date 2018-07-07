#include "stdafx.h"
#include "SpriteComponent.h"
#include "GameObject.h"
#include "ResourceManager.h"

SpriteComponent::SpriteComponent()
{
	
}


SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::Render()
{
	
}

void SpriteComponent::Update(float elapsedSec)
{
	if(m_IsAnimated)
	{
		CalculateAnimation(elapsedSec);
	}
}

void SpriteComponent::SetTexture(string name)
{
	m_pTexture = ResourceManager::GetInstance()->RequestTexture(name);

	if(m_pTexture) m_pGameObject->m_pRectangle->setTexture(m_pTexture);
	else cout << "could not load texture!" << endl;
}

void SpriteComponent::SetTextureRect(int x, int y, int w, int h)
{
	m_pGameObject->m_pRectangle->setTextureRect({ x, y, w, h });
}

void SpriteComponent::SetRepeated(bool repeated)
{
	m_pTexture->setRepeated(repeated);
}

void SpriteComponent::SetAnimated(bool isAnimated)
{
	m_IsAnimated = isAnimated;
}

void SpriteComponent::SetAnimationParams(int fps, int numbFrames, float width, float height, float startX
	, float startY)
{
	m_FPS = fps;
	m_NumberOfFrames = numbFrames - 1;
	m_SpriteWidth = width;
	m_SpriteHeight = height;
	m_StartX = startX;
	m_StartY = startY;

	SetTextureRect(0, 0,int( width), int(height));

}

void SpriteComponent::CalculateAnimation(float elapsedSec)
{
	m_ElapsedTime += elapsedSec;

	if (m_ElapsedTime >= (float)(1.0f / (m_FPS)))
	{
		++m_CurrentFrame;

		if(m_CurrentFrame > m_NumberOfFrames)
		{
			m_CurrentFrame = 0;
		}

		m_ElapsedTime = 0.0f;

		m_pGameObject->m_pRectangle->setTextureRect({ 
			int(m_StartX + (m_CurrentFrame * m_SpriteWidth))
			,int(m_StartY)
			, int(m_SpriteWidth)
			, int(m_SpriteHeight) 
		});
	}
}
