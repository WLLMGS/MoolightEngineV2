#pragma once
#include "GameObject.h"

class BulletPrefab : public GameObject
{
public:
	BulletPrefab(const float angle);
	~BulletPrefab();
private:
	virtual void HandleCollision(GameObject* other) override;
};

