#include "stdafx.h"
#include "ColliderComponent.h"
#include "GameObject.h"




ColliderComponent::ColliderComponent(bool isStatic) :
m_IsStatic(isStatic)  
{
}


ColliderComponent::~ColliderComponent()
{
}

bool ColliderComponent::CheckCollision(ColliderComponent* other)
{
	auto otherPosition = other->m_pGameObject->m_pRectangle->getPosition();
	auto otherHalfSize = other->m_pGameObject->m_pRectangle->getSize() / 2.0f;
	auto thisPosition = m_pGameObject->m_pRectangle->getPosition();
	auto thisHalfSize = m_pGameObject->m_pRectangle->getSize() / 2.0f;

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX, 0.0f);
			}
			else
			{
				Move(-intersectX, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, intersectY);
			}
			else
			{
				Move(0.0f, -intersectY);
			}
		}


		m_pGameObject->OnCollision(other);
		other->m_pGameObject->OnCollision(this);

		return true;
	}

	return false;
}

void ColliderComponent::Move(float x, float y)
{
	m_pGameObject->GetTransform().Translate(x, y);
}

bool ColliderComponent::IsStatic() const
{
	return m_IsStatic;
}

GameObject* ColliderComponent::GetGameObject()
{
	return m_pGameObject;
}
