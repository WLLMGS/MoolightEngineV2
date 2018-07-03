#pragma once
#include "GameObject.h"

class CustomContactListener : public b2ContactListener
{
public:
	virtual void BeginContact(b2Contact* contact) {
		(contact);
		//check if fixture A was a ball
		void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
		
		GameObject* o1 = static_cast<GameObject*>(bodyUserData);

		bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();

		GameObject* o2 = static_cast<GameObject*>(bodyUserData);

		o1->OnCollision(o2);
 		o2->OnCollision(o1);

		

	}
	virtual void EndContact(b2Contact* contact) {

		(contact);
		

	}

};

