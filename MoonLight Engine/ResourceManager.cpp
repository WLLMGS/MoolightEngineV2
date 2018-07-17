#include "stdafx.h"
#include "ResourceManager.h"

ResourceManager::~ResourceManager()
{
}

Texture* ResourceManager::RequestTexture(string name)
{
	return (m_Resources[name]) ? m_Resources[name] : nullptr;
}

Font* ResourceManager::RequestFont(string name)
{
	return (m_Fonts[name]) ? m_Fonts[name] : nullptr;
}

void ResourceManager::CleanUp()
{
	for(auto p : m_Resources)
	{
		delete p.second;
		p.second = nullptr;
	}

	for(auto f : m_Fonts)
	{
		delete f.second;
		f.second = nullptr;
	}
}

ResourceManager::ResourceManager()
{
	LoadTexture("character1Side", "characters/2_side.png");
	LoadTexture("character1SideFlipped", "characters/2_sideFlipped.png");

	LoadTexture("character1North", "characters/2_north.png");
	LoadTexture("character1South", "characters/2_south.png");
	LoadTexture("character1DiagDown", "characters/2_diagdown.png");
	LoadTexture("character1DiagUp", "characters/2_diagup.png");

	LoadTexture("character1DiagDownFlipped", "characters/2_diagdownFlipped.png");
	LoadTexture("character1DiagUpFlipped", "characters/2_diagupFlipped.png");

	LoadTexture("dungeonTiles", "dungeonTileset.png");
	LoadTexture("crate", "crate.jpg");
	LoadTexture("wall_right_down", "topDownBuilding/corner_right_down.png");
	LoadTexture("bullet_c", "bulletc.png");
	LoadTexture("explosion", "explode1.png");
	LoadTexture("crosshair", "1crosshair.png");
	LoadTexture("PlayButton", "PlayButton.png");
	LoadTexture("PlayButton_hover", "PlayButton_hover.png");
	LoadTexture("wall_top", "wall_uniform.png");
	LoadTexture("wall_bottom", "wall_bottom_1.png");
	LoadTexture("wall_side", "wall_side_1.png");
	LoadTexture("floor_wood", "floor_wood.png");
	LoadTexture("flame_bullet", "flame_bullet.png");
	LoadTexture("zombie_walk", "zombie_walk.png");
	LoadTexture("coin", "coin2.png");
	LoadTexture("chest", "chest1.png");
	LoadTexture("smoke", "Death_Poof.png");
	LoadTexture("title", "project_hellfire.png");
	LoadTexture("menuBackground", "menuBackground.png");

	LoadFont("default", "default.ttf");

}

void ResourceManager::LoadTexture(string name, string path)
{
	auto texture = new Texture();
	texture->loadFromFile(m_PathPrefix + path);

	m_Resources[name] = texture;
}

void ResourceManager::LoadFont(string name, string path)
{
	string p = "Resources/Fonts/" + path;

	Font* f = new Font();
	f->loadFromFile(p);

	m_Fonts[name] = f;
}
