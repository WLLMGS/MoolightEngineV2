#pragma once
#include <Windows.h>
#include <Xinput.h>

class InputManager
{
public:
	static InputManager* GetInstance()
	{
		static InputManager instance;
		return &instance;
	}
	~InputManager();
	void AddAction(int id, Keyboard::Key key);
	void Update();
	bool IsActionTriggered(int id);
	void GetThumbstickLeft(float& x, float& y);
	void GetThumbstickRight(float& x, float& y);
	bool IsButtonPressed(WORD button);
private:
	InputManager();
	map<int, Keyboard::Key> m_InputActions;
	XINPUT_STATE currentState{};
};

