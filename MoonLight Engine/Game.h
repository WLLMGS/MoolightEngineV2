#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Game
{
public:
	Game();
	void Run();
	void CleanUp();
	static RenderWindow * m_pWindow;
	virtual void Setup();
	static void Quit();
private:
	//functions
	bool ProcessEvents();
	void Update(float deltaTime);
	void Draw();

private:
	static bool m_IsRunning;
};

