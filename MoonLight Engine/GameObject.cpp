#include "stdafx.h"
#include "GameObject.h"
#include "RigidBodyComponent.h"

GameObject::GameObject()
{
	m_pRectangle = new RectangleShape();
	m_pRectangle->setSize({ 32.0f,32.0f });
	m_pRectangle->setOrigin({ 16.0f,16.0f});


}


GameObject::~GameObject()
{
	delete m_pRectangle;
	m_pRectangle = nullptr;

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

void GameObject::AddComponent(BaseComponent* comp)
{
	comp->SetGameObject(this);
	m_pComponents.push_back(comp);
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

void GameObject::SetScale(float scale)
{
	auto rigid = GetComponent<RigidBodyComponent>();
	if(rigid)
	{
		rigid->SetScale(scale);
		return;
	}

	m_pRectangle->setSize({ scale * GameSettings::TILESIZE, scale*GameSettings::TILESIZE });
	m_pRectangle->setOrigin(m_pRectangle->getSize() / 2.0f);

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


