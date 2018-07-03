#include "stdafx.h"
#include "RigidBodyComponent.h"
#include "PhysicsManager.h"
#include "GameObject.h"


RigidBodyComponent::RigidBodyComponent(short category, short mask, bool isStatic, bool isBox,  float linearDamp, float density, float friction, float restitution)
{
	m_IsStatic = isStatic;
	m_IsBox = isBox;
	m_LinDamp = linearDamp;
	m_Density = density;
	m_Friction = friction;
	m_Restitution = restitution;
	m_Category = category;
	m_Mask = mask;

	MakeBody();
}


RigidBodyComponent::~RigidBodyComponent()
{
	PhysicsManager::GetInstance()->GetWorld()->DestroyBody(m_pBody);
}

void RigidBodyComponent::Update(float elapsedSec)
{
	(elapsedSec);
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
	m_Scale = scale;
	RemakeBody();
}

WG::Vector2 RigidBodyComponent::GetPosition() const
{
	WG::Vector2 pos;

	pos.x = m_pBody->GetPosition().x;
	pos.y = m_pBody->GetPosition().y;


	return pos;
}

void RigidBodyComponent::MakeBody()
{
	auto world = PhysicsManager::GetInstance()->GetWorld();

	if (m_pBody) world->DestroyBody(m_pBody);

	b2BodyDef bd;
	bd.type = (m_IsStatic) ? b2_staticBody : b2_dynamicBody;
	bd.position.Set(0.0f, 0.0f);
	bd.allowSleep = false;
	bd.active = true;
	bd.linearDamping = m_LinDamp;
	bd.bullet = true;

	m_pBody = world->CreateBody(&bd);


	if (m_IsBox)
	{
		//box shape
		b2PolygonShape shape;
		shape.SetAsBox(GameSettings::TILESIZE / 2.0f, GameSettings::TILESIZE / 2.0f);

		//fixture
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = m_Density;
		fixtureDef.friction = m_Friction;
		fixtureDef.restitution = m_Restitution;

		//for (int i : m_CollisionGroups) fixtureDef.filter.groupIndex = int16(i);
		fixtureDef.filter.categoryBits = m_Category;
		fixtureDef.filter.maskBits = m_Mask;



		m_pBody->CreateFixture(&fixtureDef);
	}
	else
	{
		//circle shape
		b2CircleShape circle;
		circle.m_p.Set(0, 0);
		circle.m_radius = GameSettings::TILESIZE / 2.0f;

		//fixture
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &circle;
		fixtureDef.density = m_Density;
		fixtureDef.friction = m_Friction;
		fixtureDef.restitution = m_Restitution;

		fixtureDef.filter.categoryBits = m_Category;
		fixtureDef.filter.maskBits = m_Mask;

		m_pBody->CreateFixture(&fixtureDef);
	}

	m_pBody->SetUserData(m_pGameObject);


}

void RigidBodyComponent::RemakeBody()
{
	b2Vec2 pos = { 0,0 };
	if(m_pBody) pos = m_pBody->GetPosition();

	auto world = PhysicsManager::GetInstance()->GetWorld();

	if(m_pBody)world->DestroyBody(m_pBody);

	auto size = GameSettings::TILESIZE * m_Scale * 0.5f;


	b2BodyDef bd;
	bd.type = (m_IsStatic) ? b2_staticBody : b2_dynamicBody;
	bd.position.Set(pos.x, pos.y);
	bd.allowSleep = false;
	bd.active = true;
	bd.linearDamping = m_LinDamp;
	bd.bullet = true;

	m_pBody = world->CreateBody(&bd);

	

	if(m_IsBox)
	{
		//box shape
		b2PolygonShape shape;
		shape.SetAsBox(size, size);
		
		//fixture
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = m_Density;
		fixtureDef.friction = m_Friction;
		fixtureDef.restitution = m_Restitution;

		fixtureDef.filter.categoryBits = m_Category;
		fixtureDef.filter.maskBits = m_Mask;

		m_pBody->CreateFixture(&fixtureDef);
	}
	else
	{
		//circle shape
		b2CircleShape circle;
		circle.m_p.Set(0, 0);
		circle.m_radius = size;

		//fixture
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &circle;
		fixtureDef.density = m_Density;
		fixtureDef.friction = m_Friction;
		fixtureDef.restitution = m_Restitution;

		fixtureDef.filter.categoryBits = m_Category;
		fixtureDef.filter.maskBits = m_Mask;


		m_pBody->CreateFixture(&fixtureDef);
	}
	
	m_pBody->SetUserData(m_pGameObject);

	//set scale of rectangle
	if(m_pGameObject->m_pRectangle)m_pGameObject->m_pRectangle->setSize({ size * 2, size * 2 });
	if(m_pGameObject->m_pRectangle)m_pGameObject->m_pRectangle->setOrigin({ size, size });
}
