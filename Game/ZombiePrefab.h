#pragma once
#include "../MoonLight Engine/GameObject.h"
#include "HealthComponent.h"

class ZombiePrefab : public GameObject
{
public:
	ZombiePrefab();
	~ZombiePrefab();
	virtual void Init() override;
	virtual void HandleCollision(GameObject* other) override;
	virtual void OnDestroy() override;
private:
	HealthComponent* m_pHealthComponent = nullptr;
};

