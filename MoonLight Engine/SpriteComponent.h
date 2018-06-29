#pragma once
#include "BaseComponent.h"

class SpriteComponent : public BaseComponent
{
public:
	SpriteComponent();
	~SpriteComponent();
	virtual void Render() override;
	virtual void Update(float elapsedSec) override;
	void SetTexture(string name);
	void SetTextureRect(int x, int y, int w, int h);
	void SetAnimated(bool isAnimated);
	void SetAnimationParams(int fps, int numbFrames
		, float width, float height
		,float startX
		, float startY);
private:
	bool m_IsAnimated = false;

	//anim param
	int m_FPS = 0;
	int m_NumberOfFrames = 0;
	int m_CurrentFrame = 0;
	float m_ElapsedTime = 0.0f;
	float m_SpriteWidth;
	float m_SpriteHeight;
	float m_StartX;
	float m_StartY;
private:
	void CalculateAnimation(float elapsedSec);
};

