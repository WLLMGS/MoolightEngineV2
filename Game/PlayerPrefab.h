#pragma once

#include "../MoonLight Engine/GameObject.h"

class PlayerPrefab : public GameObject
{
public:
	PlayerPrefab();
	~PlayerPrefab();
	virtual void HandleCollision(GameObject* other) override;
private:
	
};

