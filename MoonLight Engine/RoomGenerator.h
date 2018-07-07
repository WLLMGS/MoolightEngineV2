#pragma once
class GameScene;

struct Doorway
{
	bool right, left, up, down;
};

class RoomGenerator
{
public:
	RoomGenerator();
	~RoomGenerator();
	static void AddRoom(GameScene* scene, const float x, const float y, Doorway& doorway);
	static void AddFloor(GameScene* scene, const float x, const float y);
};

