#pragma once

#include "../MoonLight Engine/GameObject.h"

class GameplayManager : public GameObject
{
public:
	GameplayManager();
	~GameplayManager();
	virtual void Update(float elapsedSec) override;
	virtual void Init() override;
private:
	GameObject* m_pPlayer;
};

