#pragma once

#include "../MoonLight Engine/GameScene.h"

class DemoScene : public GameScene
{
public:
	DemoScene();
	~DemoScene();
private:
	virtual void Update(float ) override{};
	virtual void Render() override{};

private:
	GameObject* pPlayer;
	GameObject* pWall;


	enum Input
	{
		Up, Down, Right, Left
	};

	
};

