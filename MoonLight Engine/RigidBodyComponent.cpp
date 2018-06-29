#include "stdafx.h"
#include "RigidBodyComponent.h"
#include "PhysicsManager.h"
#include "GameObject.h"

RigidBodyComponent::RigidBodyComponent()
{
	auto world = PhysicsManager::GetInstance()->GetWorld();

	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position.Set(0.0f, 0.0f);
	bd.allowSleep = false;
	bd.active = true;
	bd.linearDamping = 1.0f;
	bd.bullet = true;

	m_pBody = world->CreateBody(&bd);


	b2CircleShape circle;
	circle.m_p.Set(0, 0);
	circle.m_radius = GameSettings::TILESIZE / 2.0f;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circle;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.0f;
	fixtureDef.restitution = 1.0f;

	//fixtureDef.filter.groupIndex = collisionGroup;

	m_pBody->CreateFixture(&fixtureDef);



	
}


RigidBodyComponent::~RigidBodyComponent()
{

}

void RigidBodyComponent::Update(float elapsedSec)
{
	auto pos = m_pBody->GetPosition();

	m_pGameObject->m_pRectangle->setPosition(pos.x, pos.y);
}

void RigidBodyComponent::AddForce(float x, float y)
{
	m_pBody->ApplyForceToCenter({ x,y }, true);
}

void RigidBodyComponent::SetPosition(float x, float y)
{
	m_pBody->SetTransform(b2Vec2(x, y), 0.0f);
}

void RigidBodyComponent::SetLinearVelocity(float x, float y)
{
	m_pBody->SetLinearVelocity({ x,y });
}

void RigidBodyComponent::SetScale(float scale)
{
	auto pos = m_pBody->GetPosition();
	
	auto world = PhysicsManager::GetInstance()->GetWorld();

	world->DestroyBody(m_pBody);

	auto size = GameSettings::TILESIZE * scale * 0.5f;


	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position.Set(pos.x, pos.y);
	bd.allowSleep = false;
	bd.active = true;
	bd.linearDamping = 1.0f;
	bd.bullet = true;

	m_pBody = world->CreateBody(&bd);


	b2CircleShape circle;
	circle.m_p.Set(0, 0);
	circle.m_radius = size;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circle;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.0f;
	fixtureDef.restitution = 1.0f;

	//fixtureDef.filter.groupIndex = collisionGroup;

	m_pBody->CreateFixture(&fixtureDef);

	//set scale of rectangle
	m_pGameObject->m_pRectangle->setSize({size * 2, size * 2});
	m_pGameObject->m_pRectangle->setOrigin({ size, size });
}
