#include "stdafx.h"
#include "GameScene.h"
#include "GameObject.h"

GameScene::GameScene()
{
	for(auto obj : m_pObjects)
	{
		delete obj;
		obj = nullptr;
	}
}


GameScene::~GameScene()
{
	for(auto obj : m_pObjects)
	{
		delete obj;
		obj = nullptr;
	}
}

void GameScene::RootUpdate(float elapsedSec)
{
	m_Camera.Update();

	//update all game objects
	for(auto obj : m_pObjects)
	{
		obj->RootUpdate(elapsedSec);
	}
	Update(elapsedSec);
}

void GameScene::RootRender()
{
	m_Camera.Draw();

	//render all game objects
	for(auto obj : m_pObjects)
	{
		obj->RootRender();
	}

	Render();
}

void GameScene::AddChild(GameObject* obj)
{
	m_pObjects.push_back(obj);
}
