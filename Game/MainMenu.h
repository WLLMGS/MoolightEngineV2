#pragma once

#include "../MoonLight Engine/GameScene.h"

class MainMenu : public GameScene
{
public:
	MainMenu();
	~MainMenu();
	virtual void Update(float elapsedSec) override;
	virtual void Render() override;
};

