#include "stdafx.h"
#include "GameScene.h"
#include "GameObject.h"

GameScene::GameScene()
{
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
	m_Camera.Draw();
	

	//UPDATE GAMEOBJECTS
	for(size_t t{}; t < m_pObjects.size(); ++t)
	{
		auto obj = m_pObjects[t];

		if(obj->IsDestroyed())
		{
			obj->OnDestroy();
			Destroy(obj);
		}
		else obj->RootUpdate(elapsedSec);

	}

	//LATE UPDATE
	for(size_t t{}; t < m_pObjects.size(); ++t)
	{
		auto obj = m_pObjects[t];


		if(!obj->IsDestroyed())	obj->RootLateUpdate();
		/*else
		{
			Destroy(obj);
		}*/
	}


	m_Mouse.RootUpdate(elapsedSec);


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

	//Render();
}

void GameScene::RenderUI()
{
	Game::m_pWindow->setView(Game::m_pWindow->getDefaultView());
	for (auto ui : m_UI)
	{
		ui->RootRender();
	}
}

void GameScene::Init()
{
	for(auto obj : m_pObjects)
	{
		obj->RootInit();
	}
}

void GameScene::RenderMouse()
{
	m_Camera.Draw();
	m_Mouse.RootRender();
}

void GameScene::UpdateUI(float elapsedSec)
{
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
}

void GameScene::AddChild(GameObject* obj)
{
	obj->SetScene(this);
	m_pObjects.push_back(obj);
}

void GameScene::AddUIElement(GameObject* obj)
{
	obj->SetScene(this);
	m_UI.push_back(obj);
}

GameObject* GameScene::FindGameObjectByName(string name)
{
	for(auto obj : m_pObjects)
	{
		if (obj->GetName() == name) return obj;
	}
	return nullptr;
}

vector<GameObject*> GameScene::FindGameObjectsByName(string name)
{
	vector<GameObject*> results;

	for(auto obj : m_pObjects)
	{
		if (obj->GetName() == name) results.push_back(obj);
	}

	return results;
}

string GameScene::GetName() const
{
	return m_Name;
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
