#pragma once

#include "../MoonLight Engine/BaseComponent.h"

class ZombieControllerComponent : public BaseComponent
{
public:
	ZombieControllerComponent(GameObject* player);
	~ZombieControllerComponent();
	virtual void Update(float elapsedSec) override;
private:
	GameObject* m_pPlayer;

	const float m_Speed = 175.0f;
};

