#pragma once
#include "GameObject.h"

class PlayerPrefab : public GameObject
{
public:
	PlayerPrefab();
	~PlayerPrefab();
	
private:
	virtual void OnCollision(ColliderComponent* other) override;
	
};

