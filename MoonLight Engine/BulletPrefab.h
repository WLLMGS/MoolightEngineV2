#pragma once
#include "GameObject.h"

class BulletPrefab : public GameObject
{
public:
	BulletPrefab(const float angle, const float ttl);
	~BulletPrefab();
private:
	virtual void HandleCollision(GameObject* other) override;
};

