#pragma once
#include "GameObject.h"

class PlayerPrefab : public GameObject
{
public:
	PlayerPrefab();
	~PlayerPrefab();
	virtual void LateUpdate() override;
private:
	virtual void OnCollision(GameObject* other) override;
	
};

