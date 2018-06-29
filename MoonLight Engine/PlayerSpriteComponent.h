#pragma once
#include "BaseComponent.h"
#include "SpriteComponent.h"

class PlayerSpriteComponent : public BaseComponent
{
public:
	PlayerSpriteComponent();
	~PlayerSpriteComponent();
	virtual void Update(float elapsedSec) override;
	void Init();
private:
	SpriteComponent* m_pSprite = nullptr;
};

