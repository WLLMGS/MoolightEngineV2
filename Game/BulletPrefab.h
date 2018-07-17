#pragma once
#include "../MoonLight Engine/GameObject.h"

class BulletPrefab : public GameObject
{
public:
	BulletPrefab(const float angle, const float ttl, float speed);
	~BulletPrefab();
	virtual void OnDestroy() override;
private:
	virtual void HandleCollision(GameObject* other) override;

	const float m_Speed;
};

