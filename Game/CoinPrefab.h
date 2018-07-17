#pragma once
#include "../MoonLight Engine/GameObject.h"

class CoinPrefab : public GameObject
{
public:
	CoinPrefab();
	~CoinPrefab();
	virtual void Update(float elapsedSec) override;
};

