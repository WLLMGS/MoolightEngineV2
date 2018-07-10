#include "stdafx.h"
#include "ShootingComponent.h"
#include "GameObject.h"
#include "BulletPrefab.h"
#include "GameScene.h"
#include "FlameSpellPrefab.h"
#include "InputManager.h"

ShootingComponent::ShootingComponent()
{

}


ShootingComponent::~ShootingComponent()
{
}

void ShootingComponent::Update(float elapsedSec)
{
	auto input = InputManager::GetInstance();

	m_CD -= elapsedSec;

	if(	sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_CD < 0.0f)
	{
		m_CD = 0.15f;

		auto mousePos = Mouse::getPosition();

		auto worldMouse = Game::m_pWindow->mapPixelToCoords(mousePos);

		auto pos = m_pGameObject->m_pRectangle->getPosition();

		float angle = Math::CalculateAngle(pos.x, pos.y, float(worldMouse.x), float(worldMouse.y));

		Shoot(angle);
	}


	float x{}, y{};

	input->GetThumbstickRight(x, y);

	cout << x << " " << y << endl;

	if((x != 0 || y != 0) && m_CD < 0.0f)
	{
		m_CD = 0.15f;

		float angle = Math::CalculateAngle(x, y);

		Shoot(angle);
	}
}

void ShootingComponent::Shoot(float angle)
{
	auto bullet = new BulletPrefab(angle, 0.35f);

	bullet->SetPosition(m_pGameObject->GetPosition().x, m_pGameObject->GetPosition().y);

	m_pGameObject->GetScene()->AddChild(bullet);


	bullet = new BulletPrefab(angle + 0.1f, 0.35f);

	bullet->SetPosition(m_pGameObject->GetPosition().x, m_pGameObject->GetPosition().y);

	m_pGameObject->GetScene()->AddChild(bullet);

	bullet = new BulletPrefab(angle - 0.1f, 0.35f);

	bullet->SetPosition(m_pGameObject->GetPosition().x, m_pGameObject->GetPosition().y);

	m_pGameObject->GetScene()->AddChild(bullet);



	bullet = new BulletPrefab(angle + 0.15f, 0.35f);

	bullet->SetPosition(m_pGameObject->GetPosition().x, m_pGameObject->GetPosition().y);

	m_pGameObject->GetScene()->AddChild(bullet);

	bullet = new BulletPrefab(angle - 0.15f, 0.35f);

	bullet->SetPosition(m_pGameObject->GetPosition().x, m_pGameObject->GetPosition().y);

	m_pGameObject->GetScene()->AddChild(bullet);
}
