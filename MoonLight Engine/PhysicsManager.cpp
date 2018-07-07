#include "stdafx.h"
#include "PhysicsManager.h"



b2World* PhysicsManager::GetWorld()
{
	return m_pWorld;
}

PhysicsManager::PhysicsManager()
{
	m_pWorld = new b2World({ 0,0 });

	m_pWorld->SetContactListener(&m_Listener);
}


PhysicsManager::~PhysicsManager()
{

}

void PhysicsManager::Update(float elapsedSec)
{
	//m_pWorld->Step((1.0f / 60.0f),6,2);
	m_pWorld->Step(elapsedSec, 6, 2);
}

void PhysicsManager::CleanUp()
{
	delete m_pWorld;
}



