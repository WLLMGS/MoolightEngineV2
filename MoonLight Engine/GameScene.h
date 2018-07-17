#pragma once
#include "Camera.h"
#include "MousePrefab.h"

class GameObject;

class GameScene
{
public:
	GameScene();
	~GameScene();
	void RootUpdate(float elapsedSec);
	void UpdateUI(float elapsedSec);
	void RootRender(); 
	void RenderUI();
	
	void Init();

	void RenderMouse();

	void AddChild(GameObject* obj);
	void AddUIElement(GameObject* obj);

	GameObject* FindGameObjectByName(string name);
	vector<GameObject*> FindGameObjectsByName(string name);
	string GetName() const;

protected:
	Camera m_Camera;
	MousePrefab m_Mouse;
	string m_Name = "Default";
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

