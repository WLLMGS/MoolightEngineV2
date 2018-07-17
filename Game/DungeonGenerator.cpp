#include "stdafx.h"
#include "DungeonGenerator.h"
#include "RoomGenerator.h"
#include "../MoonLight Engine/GameScene.h"
#include "CratePrefab.h"
#include "ZombiePrefab.h"
#include "ChestPrefab.h"

vector<int> DungeonGenerator::m_Map;
Vector2f DungeonGenerator::m_SpawnPos;

DungeonGenerator::DungeonGenerator()
{
}


DungeonGenerator::~DungeonGenerator()
{
}

void DungeonGenerator::GenerateDungeon(GameScene* scene, int width, int height)
{
	GenerateMap(width, height);

	AddRoomsToScene(scene, width, height);
}

Vector2f DungeonGenerator::GetSpawnPos()
{
	return m_SpawnPos;
}

void DungeonGenerator::GenerateMap(int width, int height)
{
	//initializing map
	m_Map.resize(width * height);

	for(int y{}; y < height; ++y)
	{
		for(int x{}; x < width; ++x)
		{
			m_Map[y * width + x] = 0;
		}
	}
	//define room in middle

	int mx = width / 2 ;
	int my = height / 2 ;

	m_Map[my * width + mx] = CenterRoom;

	//pick room in quadrants
	
	//first quadrant
	int qx = rand() % (width / 2);
	int qy = rand() % (height / 2);
	m_Map[qy * width + qx] = SpecialRoom;
	
	if(rand() % 2 == 1)	ConnectToCenterAlternate(qx, qy, width, height);
	else ConnectToCenter(qx, qy, width, height);


	qx = rand() % (width / 2);
	qy = rand() % (height / 2);
	m_Map[qy * width + qx] = StartRoom;

	if (rand() % 2 == 1)	ConnectToCenterAlternate(qx, qy, width, height);
	else ConnectToCenter(qx, qy, width, height);

	
	//second quadrant
	qx = rand() % (width / 2) + (width / 2 + 1);
	qy = rand() % (height / 2);
	m_Map[qy * width + qx] = SpecialRoom;
	
	if (rand() % 2 == 1)	ConnectToCenterAlternate(qx, qy, width, height);
	else ConnectToCenter(qx, qy, width, height);

	qx = rand() % (width / 2) + (width / 2 + 1);
	qy = rand() % (height / 2);
	m_Map[qy * width + qx] = SpecialRoom;

	if (rand() % 2 == 1)	ConnectToCenterAlternate(qx, qy, width, height);
	else ConnectToCenter(qx, qy, width, height);
	
	//third quadrant
	qx = rand() % (width / 2);
	qy = rand() % (height / 2) + (height / 2 + 1);
	m_Map[qy * width + qx] = SpecialRoom;
	
	if (rand() % 2 == 1)	ConnectToCenterAlternate(qx, qy, width, height);
	else ConnectToCenter(qx, qy, width, height);

	qx = rand() % (width / 2);
	qy = rand() % (height / 2) + (height / 2 + 1);
	m_Map[qy * width + qx] = SpecialRoom;

	if (rand() % 2 == 1)	ConnectToCenterAlternate(qx, qy, width, height);
	else ConnectToCenter(qx, qy, width, height);
	
	//fourth quadrant
	qx = rand() % (width / 2) + (width / 2 + 1);
	qy = rand() % (height / 2) + (height / 2 + 1);
	m_Map[qy * width + qx] = SpecialRoom;
	
	if (rand() % 2 == 1)	ConnectToCenterAlternate(qx, qy, width, height);
	else ConnectToCenter(qx, qy, width, height);

	qx = rand() % (width / 2) + (width / 2 + 1);
	qy = rand() % (height / 2) + (height / 2 + 1);
	m_Map[qy * width + qx] = SpecialRoom;

	if (rand() % 2 == 1)	ConnectToCenterAlternate(qx, qy, width, height);
	else ConnectToCenter(qx, qy, width, height);
	


	PrintMap(width, height);
}

void DungeonGenerator::PrintMap(int width, int height)
{
	for (int y{}; y < height; ++y)
	{
		for (int x{}; x < width; ++x)
		{
			cout << m_Map[y * width + x] << " ";
		}
		cout << "\n";
	}
}

void DungeonGenerator::ConnectToCenter(int x, int y, int width, int height)
{
	int centerX = width / 2;
	int centerY = height / 2;
	if(x > centerX)
	{
		auto dx = x - centerX;
		for(int i{}; i < dx; ++i)
		{
			m_Map[y * width + (i + centerX)] = Hallway;
		}
	}
	else
	{
		auto dx = centerX - x;
		for(int i{}; i < dx; ++i)
		{
			m_Map[y * width + (i + x + 1)] = Hallway;
		}
	}

	if(y > centerY)
	{
		auto dy = y - centerY;
		for(int i{}; i < dy; ++i)
		{
			m_Map[(centerY + i + 1) * width + centerX] = Hallway;
		}
	}
	else
	{
		auto dy = centerY - y;
		for(int i{}; i < dy; ++i)
		{
			m_Map[(y + i) * width + centerX] = Hallway;
		}
	}

}

void DungeonGenerator::ConnectToCenterAlternate(int x, int y, int width, int height)
{
	//y first =-)
	int centerX = width / 2;
	int centerY = height / 2;
	

	if (y > centerY)
	{
		auto dy = y - centerY;
		for (int i{}; i < dy; ++i)
		{
			m_Map[(centerY + i) * width + x] = Hallway;
		}
	}
	else
	{
		auto dy = centerY - y;
		for (int i{}; i < dy; ++i)
		{
			m_Map[(y + i + 1) * width + x] = Hallway;
		}
	}



	if (x > centerX)
	{
		auto dx = x - centerX;
		for (int i{}; i < dx; ++i)
		{
			m_Map[centerY * width + (i + centerX + 1)] = Hallway;
		}
	}
	else
	{
		auto dx = centerX - x;
		for (int i{}; i < dx; ++i)
		{
			m_Map[centerY * width + (i + x)] = Hallway;
		}
	}

}

void DungeonGenerator::AddRoomsToScene(GameScene* scene, int width, int height)
{
	auto roomSize = GameSettings::ROOMSIZE * GameSettings::TILESIZE * 2.0f;

	for (int y{}; y < height; ++y)
	{
		for (int x{}; x < width; ++x)
		{
			auto index = m_Map[y * width + x];

			if (index != 0)
			{
				RoomGenerator::AddFloor(scene, roomSize * x, roomSize * y);
			}
		}
	}
	

	for(int y{}; y < height ; ++y)
	{
		for(int x{}; x < width ;++x)
		{
			auto index = m_Map[y * width + x];

			if(index != 0)
			{
				Doorway d;
				d.right = false;
				d.left = false;
				d.down = false;
				d.up = false;

				//check neighbors
				d = CheckDoorways(x, y, width, height);

				//add room
				RoomGenerator::AddRoom(scene, roomSize * x, roomSize * y, d);

				//add enemies
				if (index != SpecialRoom && index != StartRoom)
				{
					//AddScenary(scene, x, y, roomSize);
					AddEnemies(scene, x, y, roomSize);
				}
				if(index == StartRoom)
				{
					m_SpawnPos.x = roomSize * x + roomSize / 2.0f;
					m_SpawnPos.y = roomSize * y + roomSize / 2.0f;
				}
				if(index == SpecialRoom)
				{
					float cpx = roomSize * x + roomSize / 2.0f;
					float cpy = roomSize * y + roomSize / 2.0f;

					auto chest = new ChestPrefab();

					auto cSize = chest->m_pRectangle->getSize() / 2.0f;

					chest->SetPosition(cpx - cSize.x,cpy - cSize.y);
					scene->AddChild(chest);
				}


				
			}
		}
	}
}

Doorway DungeonGenerator::CheckDoorways(int x, int y, int width, int height)
{
	Doorway d;
	d.up = false;
	d.down = false;
	d.right = false;
	d.left = false;

	if(x > 0)
	{
		//check left
		if (m_Map[y * width + (x - 1)] != 0) d.left = true;
		else d.left = false;
	}

	if(x < width - 1)
	{
		//check right
		if (m_Map[y * width + (x + 1)] != 0) d.right = true;
		else d.right = false;
	}

	if (y > 0)
	{
		//check up
		if (m_Map[(y - 1) * width + x] != 0) d.up = true;
		else d.up = false;
	}

	if (y < height - 1)
	{
		//check down
		if (m_Map[(y + 1) * width + x] != 0) d.down = true;
		else d.down = false;
	}
	return d;
}

void DungeonGenerator::AddScenary(GameScene* scene, int x, int y, int roomsize)
{
	int amountOfCrates = rand() % 5;
	int tilesize = int(GameSettings::TILESIZE) * 2.0f;

	
	--amountOfCrates;

	for(int i{0}; i < amountOfCrates; ++i)
	{
		int xPos = rand() % (roomsize - (tilesize * 4)) + (x * roomsize) + tilesize;
		int yPos = rand() % (roomsize - (tilesize * 4)) + (y * roomsize) + tilesize;

		auto crate = new CratePrefab();
		crate->SetPosition(float(xPos),float(yPos));
		scene->AddChild(crate);
	}
}

void DungeonGenerator::AddEnemies(GameScene* scene, int x, int y, int roomsize)
{
	int amountOfZombies = rand() % 7;
	int tilesize = int(GameSettings::TILESIZE) * 2.0f;



	for (int i{ 0 }; i < amountOfZombies; ++i)
	{
		int xPos = rand() % (roomsize - (tilesize * 4)) + (x * roomsize) + tilesize;
		int yPos = rand() % (roomsize - (tilesize * 4)) + (y * roomsize) + tilesize;

		auto zombie = new ZombiePrefab();
		zombie->SetPosition(float(xPos), float(yPos));
		scene->AddChild(zombie);
	}
}
