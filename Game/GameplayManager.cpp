#include "stdafx.h"
#include "GameplayManager.h"
#include "../MoonLight Engine/InputManager.h"
#include "../MoonLight Engine/GameScene.h"
#include "HealthComponent.h"
#include "../MoonLight Engine/SceneManager.h"

GameplayManager::GameplayManager()
{
	auto input = InputManager::GetInstance();
	input->AddAction(GameSettings::Input ::Escape, Keyboard::Escape);
	
	m_pRectangle->setFillColor(Color::Transparent);
}


GameplayManager::~GameplayManager()
{
}

void GameplayManager::Update(float)
{
	auto input = InputManager::GetInstance();

	if(input->IsActionTriggered(GameSettings::Input::Escape))
	{
		SceneManager::GetInstance()->GoToScene("Pause Menu");
	}
}

void GameplayManager::Init()
{
	m_pPlayer = GetScene()->FindGameObjectByName("Player");

	auto health = m_pPlayer->GetComponent<HealthComponent>();
}
