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
	void AddUIElement(GameObject* obj);

protected:
	Camera m_Camera;
private:
	virtual void Update(float elapsedSec) = 0;
	virtual void Render() = 0;
private:
	vector<GameObject*> m_pObjects;
	vector<GameObject*> m_UI;

private:
	void Destroy(GameObject* obj);
	void DestroyUI(GameObject* ui);
};

