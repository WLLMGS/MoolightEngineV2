#include "stdafx.h"
#include "GameObject.h"
#include "RigidBodyComponent.h"
#include "GameScene.h"

GameObject::GameObject()
{
	m_Size = { GameSettings::TILESIZE, GameSettings::TILESIZE };
	m_pRectangle = new RectangleShape();
	m_pRectangle->setSize(m_Size);
	m_pRectangle->setOrigin(m_Size / 2.0f);
}


GameObject::~GameObject()
{
	
	if(m_pRectangle)
	{
		delete m_pRectangle;
		m_pRectangle = nullptr;
	}
	
	
	for(auto comp : m_pComponents)
	{
		delete comp;
		comp = nullptr;
	}
}

void GameObject::RootUpdate(float elapsedSec)
{
	for (auto comp : m_pComponents) comp->Update(elapsedSec);
	Update(elapsedSec);
}

void GameObject::RootRender()
{
	Game::m_pWindow->draw(*m_pRectangle);
	for (auto comp : m_pComponents) comp->Render();
	Render();
}

void GameObject::RootLateUpdate()
{

	LateUpdate();

	m_CollisionEvents.clear();
}

void GameObject::RootInit()
{
	for (auto comp : m_pComponents) comp->Init();

	Init();
}


void GameObject::LateUpdate()
{
	for(auto obj : m_CollisionEvents)
	{
		HandleCollision(obj);
	}
}

void GameObject::AddComponent(BaseComponent* comp)
{
	comp->SetGameObject(this);
	m_pComponents.push_back(comp);

	comp->Init();
}


string GameObject::GetTag() const
{
	return m_Tag;
}

void GameObject::SetPosition(float x, float y)
{
	auto rigid = GetComponent<RigidBodyComponent>();
	if (rigid) 
	{
		rigid->SetPosition(x, y);
		return;
	}

	m_pRectangle->setPosition({ x,y });

}

void GameObject::Translate(float x, float y)
{
	float dx = x + m_pRectangle->getPosition().x;
	float dy = y + m_pRectangle->getPosition().y;

	SetPosition(dx, dy);
}

void GameObject::SetScale(float scale)
{
	m_Scale = scale;
	auto rigid = GetComponent<RigidBodyComponent>();
	if(rigid)
	{
		rigid->SetScale(scale);
		return;
	}

	m_pRectangle->setSize({ scale * m_Size.x, scale* m_Size.y });
	m_pRectangle->setOrigin(m_pRectangle->getSize() / 2.0f);

}

float GameObject::GetScale() const
{
	return m_Scale;
}

WG::Vector2 GameObject::GetPosition()
{
	WG::Vector2 pos;


	auto rigid = GetComponent<RigidBodyComponent>();
	
	if(rigid)
	{
		return rigid->GetPosition();
	}

	pos.x = m_pRectangle->getPosition().x;
	pos.y = m_pRectangle->getPosition().y;

	return pos;

}

void GameObject::OnCollision(GameObject* other)
{
	m_CollisionEvents.push_back(other);
}

void GameObject::Destroy()
{
	m_IsDestroyed = true;
}

bool GameObject::IsDestroyed() const
{
	return m_IsDestroyed;
}

void GameObject::SetScene(GameScene* scene)
{
	m_pScene = scene;
}

GameScene* GameObject::GetScene() const
{
	return m_pScene;
}

void GameObject::SetSize(float x, float y)
{
	m_Size.x = x;
	m_Size.y = y;

	m_pRectangle->setSize(m_Size);
	m_pRectangle->setOrigin(m_Size / 2.0f);


	SetScale(m_Scale);
}

Vector2f GameObject::GetOriginalSize()
{
	return m_Size;
}

string GameObject::GetName() const
{
	return m_Name;
}


