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
	for(auto ui : m_UI)
	{
		delete ui;
		ui = nullptr;
	}
	for(auto obj : m_pObjects)
	{
		delete obj;
		obj = nullptr;
	}
}

void GameScene::RootUpdate(float elapsedSec)
{
	m_Camera.Update();

	//UI
	for (size_t t{}; t < m_UI.size(); ++t)
	{
		auto obj = m_UI[t];

		if (obj->IsDestroyed())
		{
			DestroyUI(obj);
		}
		else obj->RootUpdate(elapsedSec);

	}

	//UPDATE GAMEOBJECTS
	for(size_t t{}; t < m_pObjects.size(); ++t)
	{
		auto obj = m_pObjects[t];

		if(obj->IsDestroyed())
		{
			Destroy(obj);
		}
		else obj->RootUpdate(elapsedSec);

	}

	//LATE UPDATE
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
	//render UI
	Game::m_pWindow->setView(Game::m_pWindow->getDefaultView());
	for (auto ui : m_UI)
	{
		ui->RootRender();
	}


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

void GameScene::AddUIElement(GameObject* obj)
{
	obj->SetScene(this);
	m_UI.push_back(obj);
}

void GameScene::Destroy(GameObject* obj)
{
	m_pObjects.erase(std::remove(m_pObjects.begin(), m_pObjects.end(), obj), m_pObjects.end());
	delete obj;
	obj = nullptr;
}

void GameScene::DestroyUI(GameObject* ui)
{
	m_UI.erase(std::remove(m_pObjects.begin(), m_pObjects.end(), ui), m_pObjects.end());
	delete ui;
	ui = nullptr;

}
