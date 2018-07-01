#pragma once
#include "Camera.h"

class GameObject;

class GameScene
{
public:
	GameScene();
	~GameScene();
	void RootUpdate(float elapsedSec);
	void RootRender(); 
	void AddChild(GameObject* obj);

protected:
	Camera m_Camera;
private:
	virtual void Update(float elapsedSec) = 0;
	virtual void Render() = 0;
private:
	vector<GameObject*> m_pObjects;
private:
	void Destroy(GameObject* obj);
};

