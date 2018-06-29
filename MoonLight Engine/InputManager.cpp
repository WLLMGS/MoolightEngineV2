#include "stdafx.h"
#include "InputManager.h"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::AddAction(int id, Keyboard::Key key)
{
	m_InputActions[id] = key;
}

bool InputManager::IsActionTriggered(int id)
{
	return (Keyboard::isKeyPressed(m_InputActions[id]));
}
