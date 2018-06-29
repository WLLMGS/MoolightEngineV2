#pragma once
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
	bool IsActionTriggered(int id);
private:
	InputManager();
	map<int, Keyboard::Key> m_InputActions;
};

