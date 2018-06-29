#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Game
{
public:
	Game();
	void Run();

	static RenderWindow * m_pWindow;
private:
	//functions
	bool ProcessEvents();
	void Update(float deltaTime);
	void Draw();
	void CleanUp();
	
	//members
	
	
};

