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
	/*for(auto obj : m_pObjects)
	{
		obj->RootUpdate(elapsedSec);
	}*/

	for(size_t t{}; t < m_pObjects.size(); ++t)
	{
		auto obj = m_pObjects[t];

		if(obj->IsDestroyed())
		{
			Destroy(obj);
		}
		else obj->RootUpdate(elapsedSec);

	}
	for(auto obj : m_pObjects)
	{
		if(!obj->IsDestroyed())	obj->RootLateUpdate();
		else
		{
			Destroy(obj);
		}
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
	obj->SetScene(this);
}

void GameScene::Destroy(GameObject* obj)
{
	m_pObjects.erase(std::remove(m_pObjects.begin(), m_pObjects.end(), obj), m_pObjects.end());
	delete obj;
	obj = nullptr;
}
