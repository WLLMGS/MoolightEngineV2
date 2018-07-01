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
	void RootLateUpdate();

	virtual void LateUpdate(){};

	void AddComponent(BaseComponent* comp);
	string GetTag() const;
	void SetPosition(float x, float y);
	void SetScale(float scale);
	WG::Vector2 GetPosition();
	virtual void OnCollision(GameObject* other) { (other); }; 
	void Destroy();
	bool IsDestroyed() const;
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
	vector<GameObject*> m_CollisionEvents;

private:
	virtual void Update(float elapsedSec) { (elapsedSec); };
	virtual void Render(){};

	

private:
	friend class SpriteComponent;
	//friend class TransformComponent;
	friend class ColliderComponent;
	friend class RigidBodyComponent;
	friend class PlayerSpriteComponent;

	//TransformComponent m_Transform;
	vector<BaseComponent*> m_pComponents;
	bool m_IsDestroyed = false;

	
};

