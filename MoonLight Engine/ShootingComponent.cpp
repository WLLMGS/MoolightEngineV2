#include "stdafx.h"
#include "ShootingComponent.h"
#include "GameObject.h"
#include "BulletPrefab.h"
#include "GameScene.h"
#include "FlameSpellPrefab.h"
#include "InputManager.h"

ShootingComponent::ShootingComponent(const float cooldown) :
m_Cooldown(cooldown)
{
}


ShootingComponent::~ShootingComponent()
{
}

void ShootingComponent::Update(float elapsedSec)
{
	auto input = InputManager::GetInstance();

	m_Timer -= elapsedSec;

	if(	sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_Timer < 0.0f)
	{
		m_Timer = m_Cooldown;

		auto mousePos = Mouse::getPosition();

		auto worldMouse = Game::m_pWindow->mapPixelToCoords(mousePos);

		auto pos = m_pGameObject->m_pRectangle->getPosition();

		float angle = Math::CalculateAngle(pos.x, pos.y, float(worldMouse.x), float(worldMouse.y));

		Shoot(angle);
	}


	float x{}, y{};

	input->GetThumbstickRight(x, y);

	if((x != 0 || y != 0) && m_Timer < 0.0f)
	{
		m_Timer = m_Cooldown;

		float angle = Math::CalculateAngle(x, y);

		Shoot(angle);
	}
}

void ShootingComponent::Shoot(float angle)
{
	auto bullet = new BulletPrefab(angle, 0.35f);

	bullet->SetPosition(m_pGameObject->GetPosition().x, m_pGameObject->GetPosition().y);

	m_pGameObject->GetScene()->AddChild(bullet);


	/*for(int i{1}; i < 1; ++i)
	{
		float e = (i * 10) * Math::Deg2Rad;

		bullet = new BulletPrefab(angle - e, 0.35f);
		bullet->SetPosition(m_pGameObject->GetPosition().x, m_pGameObject->GetPosition().y);
		m_pGameObject->GetScene()->AddChild(bullet);


		bullet = new BulletPrefab(angle + e, 0.35f);
		bullet->SetPosition(m_pGameObject->GetPosition().x, m_pGameObject->GetPosition().y);
		m_pGameObject->GetScene()->AddChild(bullet);

	}*/

	/*float r = 96.0f;
	float a = 360.0f / 20;
*/
	
	
	//for(int i{}; i < 20; ++i)
	//{
	//	float locAngle = a * i;
	//	
	//	locAngle *= Math::Deg2Rad;
	//	//cout << locAngle << endl;
	//	float posX = r * cos(locAngle) + worldPos.x;
	//	float posY = r * sin(locAngle) + worldPos.y;

	//	cout << posX << " " << posY << endl;

	//	bullet = new BulletPrefab(angle, 0.35f);
	//	bullet->SetPosition(posX, posY);
	//	m_pGameObject->GetScene()->AddChild(bullet);
	//}

	

}
