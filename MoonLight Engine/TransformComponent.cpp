#include "stdafx.h"
#include "TransformComponent.h"
#include "GameObject.h"

TransformComponent::TransformComponent()
{
	//m_pRectangle.setPosition(m_Position);
}


TransformComponent::~TransformComponent()
{
	
}

void TransformComponent::Update(float elapsedSec)
{
	(elapsedSec);
}

void TransformComponent::Render()
{
}

void TransformComponent::SetPosition(const Vector2f& pos)
{
	m_Position = pos;
	m_pGameObject->m_pRectangle->setPosition(m_Position);
}

void TransformComponent::SetPosition(const float x, const float y)
{
	m_Position.x = x;
	m_Position.y = y;
	m_pGameObject->m_pRectangle->setPosition(m_Position);
}

void TransformComponent::Translate(const float x, const float y)
{
	m_Position.x += x;
	m_Position.y += y;
	m_pGameObject->m_pRectangle->setPosition(m_Position);

}

void TransformComponent::SetAngle(const float angle)
{
	m_Angle = angle;
}

void TransformComponent::SetScale(float scale)
{
	m_Scale = scale;
	m_pGameObject->m_pRectangle->setSize({ GameSettings::TILESIZE * scale, GameSettings::TILESIZE * scale });
	m_pGameObject->m_pRectangle->setOrigin(m_pGameObject->m_pRectangle->getSize() / 2.0f);
}

Vector2f TransformComponent::GetPosition() const
{
	return m_Position;
}

float TransformComponent::GetAngle() const
{
	return m_Angle;
}

float TransformComponent::GetScale() const
{
	return m_Scale;
}
