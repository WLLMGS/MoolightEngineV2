#pragma once
#include "RoomGenerator.h"
class GameScene;

enum RoomCode
{
	SpecialRoom = 1,
	CenterRoom = 2,
	Hallway = 3,
	StartRoom = 4

};


class DungeonGenerator
{
public:
	DungeonGenerator();
	~DungeonGenerator();
	static void GenerateDungeon(GameScene* scene,int width, int height);
	static Vector2f GetSpawnPos();
private:
	static vector<int> m_Map;
	static Vector2f m_SpawnPos;

private:
	static void GenerateMap(int width, int height);
	static void PrintMap(int width, int height);
	static void ConnectToCenter(int x, int y, int widht, int height);
	static void ConnectToCenterAlternate(int x, int y, int widht, int height);
	static void AddRoomsToScene(GameScene* scene, int width, int height);
	static Doorway  CheckDoorways(int x, int y, int width, int height);
	
};

