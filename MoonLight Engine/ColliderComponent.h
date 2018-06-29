#pragma once
#include "BaseComponent.h"

class ColliderComponent : public BaseComponent
{
public:
	ColliderComponent(bool isStatic = false);
	~ColliderComponent();
	bool CheckCollision(ColliderComponent* other);
	void Move(float x, float y);
	bool IsStatic() const;
	GameObject* GetGameObject();
private:
	bool m_IsStatic = false;
};

