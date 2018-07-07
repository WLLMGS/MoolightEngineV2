#pragma once
#include "BaseComponent.h"
#include <functional>

class ButtonComponent : public BaseComponent
{
public:
	ButtonComponent(string texNormal, string texHover);
	~ButtonComponent();
	virtual void Update(float elapsedSec) override;
	void OnClick(function<void()> func);
	void SetTextures(string normal, string hover);
private:
	float m_Cooldown = 0.1f;
	float m_Timer = 0.0f;
	bool m_IsHovering = false;
	function<void()> m_OnClick;


	string m_TextureNormal;
	string m_TextureHover;
private:
	void CheckHover();
};

