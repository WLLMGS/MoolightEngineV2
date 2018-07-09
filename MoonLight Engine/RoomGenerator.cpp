#include "stdafx.h"
#include "RoomGenerator.h"
#include "WallPrefab.h"
#include "GameScene.h"
#include "FloorPrefab.h"
#include "ZombiePrefab.h"

RoomGenerator::RoomGenerator()
{
}


RoomGenerator::~RoomGenerator()
{
}

void RoomGenerator::AddRoom(GameScene* scene, const float x, const float y, Doorway& doorway)
{
	const int width = GameSettings::ROOMSIZE;
	const float tilesize = GameSettings::TILESIZE;


	/*auto floor = new FloorPrefab(x -tilesize * 0.5f, y - tilesize * 0.5f, width * tilesize * 2.0f , width * tilesize * 2.0f );
	scene->AddChild(floor);
*/

	//horizontal
	for(int i{}; i < width + 2; ++i)
	{

		if(!doorway.up)
		{
			//top
			auto wall = new WallPrefab(Top);
			wall->SetPosition(x + tilesize * wall->GetScale() * (i-1), y);
			scene->AddChild(wall);
		}
		

		if(!doorway.down)
		{
			//bottom
			auto wall = new WallPrefab(Bottom);
			wall->SetPosition(x + tilesize * wall->GetScale() * (i-1)
				, y + width * tilesize * wall->GetScale() - tilesize * wall->GetScale());
			scene->AddChild(wall);
		}
		
	
	}

	//vertical
	for (int i{}; i < width; ++i)
	{
		//left
		if(!doorway.left)
		{
			auto wall = new WallPrefab(Left);
			wall->SetPosition(x, y + tilesize * wall->GetScale() * i);
			scene->AddChild(wall);
		}
		if (!doorway.right)
		{
			auto wall = new WallPrefab(Right);
			wall->SetPosition(x + width * tilesize * wall->GetScale() - (tilesize * wall->GetScale()), y + tilesize * wall->GetScale() * i);
			scene->AddChild(wall);			
		}
	}

	float centerX = width * 0.5f * tilesize + x;
	float centerY = width * 0.5f * tilesize + y;


	auto zombie = new ZombiePrefab();
	zombie->SetPosition(centerX, centerY);
	scene->AddChild(zombie);

	zombie = new ZombiePrefab();
	zombie->SetPosition(centerX - 1.0f, centerY);
	scene->AddChild(zombie);

	zombie = new ZombiePrefab();
	zombie->SetPosition(centerX + 1.0f, centerY);
	scene->AddChild(zombie);


	zombie = new ZombiePrefab();
	zombie->SetPosition(centerX, centerY + 1.0f);
	scene->AddChild(zombie);

	zombie = new ZombiePrefab();
	zombie->SetPosition(centerX - 1.0f, centerY + 1.0f);
	scene->AddChild(zombie);

	zombie = new ZombiePrefab();
	zombie->SetPosition(centerX + 1.0f, centerY + 1.0f);
	scene->AddChild(zombie);

}

void RoomGenerator::AddFloor(GameScene* scene, const float x, const float y)
{
	const int width = GameSettings::ROOMSIZE;
	const float tilesize = GameSettings::TILESIZE;


	auto floor = new FloorPrefab(x - tilesize * 0.5f, y - tilesize * 0.5f, width * tilesize * 2.0f, width * tilesize * 2.0f);
	scene->AddChild(floor);
}
