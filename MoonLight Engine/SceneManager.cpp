#include "stdafx.h"
#include "SceneManager.h"
#include "GameScene.h"

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
	
}



void SceneManager::Update(float elapsedSec)
{
	m_pScenes[m_ActiveScene]->RootUpdate(elapsedSec);

	m_pScenes[m_ActiveScene]->UpdateUI(elapsedSec);

}

void SceneManager::Render()
{
	m_pScenes[m_ActiveScene]->RootRender();
	m_pScenes[m_ActiveScene]->RenderUI();
	m_pScenes[m_ActiveScene]->RenderMouse();
}

void SceneManager::AddScene(GameScene* scene)
{
	m_pScenes.push_back(scene);


	//maybe here?
	scene->Init();
}

void SceneManager::CleanUp()
{
	for (auto scene : m_pScenes)
	{
		delete scene;
		scene = nullptr;
	}
}

void SceneManager::NextScene()
{
	if(m_ActiveScene == m_pScenes.size() - 1)
	{
		m_ActiveScene = 0;
	}
	else m_ActiveScene++;
}
