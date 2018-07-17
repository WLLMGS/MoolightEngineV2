#include "stdafx.h"
#include "Game.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "PhysicsManager.h"
#include <chrono>
#include "InputManager.h"

using namespace std;

RenderWindow* Game::m_pWindow = new RenderWindow(VideoMode{3840,2160}, "ENGINE", Style::Fullscreen);
bool Game::m_IsRunning;

Game::Game() 
{	
	m_IsRunning = true;
	m_pWindow->setVerticalSyncEnabled(true);
}

void Game::Run()
{
	Setup();

	Clock clock;
	float deltaTime{};
	
	while (m_IsRunning)
	{
		deltaTime = float(clock.restart().asSeconds());

		m_IsRunning = ProcessEvents();
		if (!m_IsRunning) return;
		
		Update(deltaTime);
		Draw();
	}
}

void Game::Setup()
{
	//SceneManager::GetInstance()->AddScene(new MainMenu());
	//SceneManager::GetInstance()->AddScene(new DemoScene());
	PhysicsManager::GetInstance()->GetWorld();
}

void Game::Quit()
{
	m_IsRunning = false;
}

bool Game::ProcessEvents()
{
	Event event;
	while (m_pWindow->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_pWindow->close();
			return false;
		}
	}

	return true;
}
void Game::Update(float elapsedSec)
{
	InputManager::GetInstance()->Update();
	SceneManager::GetInstance()->Update(elapsedSec);
	PhysicsManager::GetInstance()->Update(elapsedSec);
}

void Game::Draw()
{
	m_pWindow->clear();
	SceneManager::GetInstance()->Render();
	m_pWindow->display();
}

void Game::CleanUp()
{
	SceneManager::GetInstance()->CleanUp();
	ResourceManager::GetInstance()->CleanUp();
	PhysicsManager::GetInstance()->CleanUp();
	delete m_pWindow;
	m_pWindow = nullptr;
}
