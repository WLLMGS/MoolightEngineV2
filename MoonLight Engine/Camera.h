#pragma once
#include "GameObject.h"

class Camera
{
public:
	Camera();
	~Camera();
	void Update();
	void Draw();
	void Set(GameObject* target, WG::Vector2 size, float zoom);
	void SetEnabled(bool enabled);
private:
	View m_View;
	
private:
	GameObject* m_Target;
	WG::Vector2 m_Size;
	float m_Zoom;

	bool m_IsSet = false;
};

