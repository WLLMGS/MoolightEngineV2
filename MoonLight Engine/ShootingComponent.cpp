#include "stdafx.h"
#include "ShootingComponent.h"
#include "GameObject.h"
#include "BulletPrefab.h"
#include "GameScene.h"

ShootingComponent::ShootingComponent()
{

}


ShootingComponent::~ShootingComponent()
{
}

void ShootingComponent::Update(float elapsedSec)
{
	m_CD -= elapsedSec;

	if(	sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_CD < 0.0f)
	{
		m_CD = 0.10f;

		auto mousePos = Mouse::getPosition();

		auto worldMouse = Game::m_pWindow->mapPixelToCoords(mousePos);

		auto pos = m_pGameObject->m_pRectangle->getPosition();

		float angle = Math::CalculateAngle(pos.x, pos.y, float(worldMouse.x), float(worldMouse.y));

		
		auto bullet = new BulletPrefab(angle);
	
		bullet->SetPosition(m_pGameObject->GetPosition().x, m_pGameObject->GetPosition().y);

		m_pGameObject->GetScene()->AddChild(bullet);

	}
}
