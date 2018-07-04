#include "stdafx.h"
#include "Game.h"
#include "DemoScene.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "PhysicsManager.h"
#include "MainMenu.h"

using namespace std;

RenderWindow* Game::m_pWindow = new RenderWindow(VideoMode::getDesktopMode(), "ENGINE", Style::Fullscreen);


Game::Game() 
{	
	SceneManager::GetInstance()->AddScene(new MainMenu());
	SceneManager::GetInstance()->AddScene(new DemoScene());
	PhysicsManager::GetInstance()->GetWorld();
}

void Game::Run()
{
	Clock clock;
	float deltaTime{};
	
	bool isRunning = true;


	while (isRunning)
	{
		deltaTime = clock.restart().asSeconds();

		isRunning = ProcessEvents();
		if (!isRunning) return;
		
		Update(deltaTime);
		Draw();
	}
}

bool Game::ProcessEvents()
{
	Event event;
	while (m_pWindow->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_pWindow->close();
			CleanUp();
			return false;
		}
	}

	return true;
}
void Game::Update(float elapsedSec)
{
	SceneManager::GetInstance()->Update(elapsedSec);

	//[IMPORTANT] update physics after everything else -> otherwise lag spikes may occur!!! :)
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
