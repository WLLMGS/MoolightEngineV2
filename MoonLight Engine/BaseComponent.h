#pragma once
#include "Game.h"

class GameObject;

class BaseComponent
{
public:
	BaseComponent();
	~BaseComponent();
	
	virtual void Update(float elapsedSec) ;
	virtual void Render() ;
	void SetGameObject(GameObject* obj);
protected:
	GameObject* m_pGameObject;
};

