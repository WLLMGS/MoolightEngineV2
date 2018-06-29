#pragma once
#include "GameScene.h"
class DemoScene : public GameScene
{
public:
	DemoScene();
	~DemoScene();
private:
	virtual void Update(float elapsedSec) override;
	virtual void Render() override;

private:
	GameObject* pPlayer;
	GameObject* pWall;


	enum Input
	{
		Up, Down, Right, Left
	};
};

