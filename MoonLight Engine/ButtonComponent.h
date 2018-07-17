#pragma once
#include "BaseComponent.h"
#include <functional>

class ButtonComponent : public BaseComponent
{
public:
	ButtonComponent();
	~ButtonComponent();
	virtual void Init() override;
	virtual void Update(float elapsedSec) override;
	void OnClick(function<void()> func);
private:
	float m_Cooldown = 0.1f;
	float m_Timer = 0.0f;
	bool m_IsHovering = false;
	function<void()> m_OnClick;

	const Color m_ColorNormal;
	const Color m_ColorHover;

private:
	void CheckHover();
};

