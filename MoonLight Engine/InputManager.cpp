#include "stdafx.h"
#include "InputManager.h"
#include <minwinbase.h>
#include <Xinput.h>

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

void InputManager::Update()
{
	ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &currentState);
}

bool InputManager::IsActionTriggered(int id)
{
	return (Keyboard::isKeyPressed(m_InputActions[id]));
}

void InputManager::GetThumbstickLeft(float& x, float& y)
{
	x = currentState.Gamepad.sThumbLX;
	y = -float(currentState.Gamepad.sThumbLY);

	x /= 32768.0;
	y /= 32768.0;

	if (abs(x) < 0.19f) x = 0.0f;
	if (abs(y) < 0.19f) y = 0.0f;
}

void InputManager::GetThumbstickRight(float& x, float& y)
{
	x = currentState.Gamepad.sThumbRX;
	y = -float(currentState.Gamepad.sThumbRY);

	x /= 32768.0;
	y /= 32768.0;

	if (abs(x) < 0.19f) x = 0.0f;
	if (abs(y) < 0.19f) y = 0.0f;
}

bool InputManager::IsButtonPressed(WORD button)
{
	return (currentState.Gamepad.wButtons & button) != 0;
}
