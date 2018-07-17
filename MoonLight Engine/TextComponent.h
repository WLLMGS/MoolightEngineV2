#pragma once
#include "BaseComponent.h"

class TextComponent : public BaseComponent
{
public:
	TextComponent(string font, string text, int fontsize = 48, float offsetX = 0.f, float offsetY = 0.0f);
	~TextComponent();
	void SetText(string text);
	void SetColor(Color& color);
	virtual void Update(float elapsedSec) override;
	virtual void Render() override;
private:
	Text m_Text;
	float m_OffsetX;
	float m_OffsetY;
};

