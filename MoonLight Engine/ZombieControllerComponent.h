#pragma once
#include "BaseComponent.h"

class ZombieControllerComponent : public BaseComponent
{
public:
	ZombieControllerComponent(GameObject* player);
	~ZombieControllerComponent();
	virtual void Update(float elapsedSec) override;
private:
	GameObject* m_pPlayer;

	const float m_Speed = 100.0f;
};

