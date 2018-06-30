#pragma once
#include "CustomContactListener.h"
class PhysicsManager
{
public:
	static PhysicsManager* GetInstance()
	{
		static PhysicsManager instance;

		return &instance;
	}
	~PhysicsManager();
	void Update(float elapsedSec);
	void CleanUp();
	b2World* GetWorld();
private:
	PhysicsManager();
	b2World* m_pWorld = nullptr;
	CustomContactListener m_Listener;

};

