#pragma once
#include "BaseComponent.h"

class TransformComponent : public BaseComponent
{
public:
	TransformComponent();
	~TransformComponent();
	
	virtual void Update(float elapsedSec) override;
	virtual void Render() override;

	void SetPosition(const Vector2f& pos);
	void SetPosition(const float x,const float y);
	void Translate(const float x, const float y);
	void SetAngle(const float angle);
	void SetScale(float scale);

	Vector2f GetPosition() const;
	float GetAngle() const;
	float GetScale() const;
private:
	
	Vector2f m_Position;
	float m_Angle = 0.0f;
	float m_Scale = 1.0f;

};

