#pragma once
#include "BaseComponent.h"
#include "SpriteComponent.h"

class GameScene;

class GameObject
{
public:
	GameObject();
	~GameObject();
	void RootUpdate(float elapsedSec);
	void RootRender();
	void RootLateUpdate();

	void RootInit();
	

	void LateUpdate();

	void AddComponent(BaseComponent* comp);
	string GetTag() const;
	void SetPosition(float x, float y);
	void Translate(float x, float y);
	void SetScale(float scale);
	float GetScale() const;
	WG::Vector2 GetPosition();
	void OnCollision(GameObject* other); 
	void Destroy();
	bool IsDestroyed() const;

	void SetScene(GameScene* scene);
	GameScene* GetScene() const;

	void SetSize(float x, float y);
	Vector2f GetOriginalSize();
	string GetName() const;
	virtual void OnDestroy(){};
	
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

	RectangleShape* m_pRectangle;
	
protected:
	string m_Tag;
	string m_Name = "Default";
	vector<GameObject*> m_CollisionEvents;
	GameScene* m_pScene;
	float m_Scale = 1;

	Vector2f m_Size;
private:
	virtual void Update(float elapsedSec) { (elapsedSec); };
	virtual void Render(){};
	virtual void HandleCollision(GameObject* other) { (other); };
	virtual void Init(){};
	
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

