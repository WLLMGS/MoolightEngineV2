#pragma once
#include "../MoonLight Engine/GameScene.h"

class PauseMenu : public GameScene
{
public:
	PauseMenu();
	~PauseMenu();
	virtual void Update(float elapsedSec) override;
	virtual void Render() override{};
};

