#pragma once
#include "GameObject.h"
#include "HealthComponent.h"

class ZombiePrefab : public GameObject
{
public:
	ZombiePrefab();
	~ZombiePrefab();
	virtual void Init() override;
	virtual void OnCollision(GameObject* other) override;

private:
	HealthComponent* m_pHealthComponent = nullptr;
};

