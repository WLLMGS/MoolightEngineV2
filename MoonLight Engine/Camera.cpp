#include "stdafx.h"
#include "Camera.h"


Camera::Camera() 
{
	
}


Camera::~Camera()
{
}

void Camera::Update()
{
	if(m_IsSet) m_View.setCenter(m_Target->GetPosition().x, m_Target->GetPosition().y);
}

void Camera::Draw()
{
	if(m_IsSet)	Game::m_pWindow->setView(m_View);
}

void Camera::Set(GameObject* target, WG::Vector2 size, float zoom)
{
	m_Target = target;
	m_Size = size;
	m_Zoom = zoom;

	m_View.setSize(size.x, size.y);
	m_View.zoom(m_Zoom);


	m_IsSet = true;
}

void Camera::SetEnabled(bool enabled)
{
	m_IsSet = enabled;

	if (!m_IsSet) Game::m_pWindow->setView(Game::m_pWindow->getDefaultView());
}
