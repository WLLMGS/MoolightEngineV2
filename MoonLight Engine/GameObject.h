#pragma once
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "ColliderComponent.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
	void RootUpdate(float elapsedSec);
	void RootRender();
	void AddComponent(BaseComponent* comp);
	string GetTag() const;
	void SetPosition(float x, float y);
	void SetScale(float scale);
public:
	template<class T> T* GetComponent()
	{
		const type_info& ti = typeid(T);
		for (auto *component : m_pComponents)
		{
			if (component && typeid(*component) == ti)
				return static_cast<T*>(component);
		}
		return nullptr;
	}

protected:
	string m_Tag;
	RectangleShape* m_pRectangle;

private:
	virtual void Update(float elapsedSec) { (elapsedSec); };
	virtual void Render(){};

	virtual void OnCollision(ColliderComponent* other) { (other); };

private:
	friend class SpriteComponent;
	//friend class TransformComponent;
	friend class ColliderComponent;
	friend class RigidBodyComponent;
	friend class PlayerSpriteComponent;

	//TransformComponent m_Transform;
	vector<BaseComponent*> m_pComponents;

	
};

