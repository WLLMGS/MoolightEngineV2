#include "stdafx.h"
#include "ResourceManager.h"

ResourceManager::~ResourceManager()
{
}

Texture* ResourceManager::RequestTexture(string name)
{
	return (m_Resources[name]) ? m_Resources[name] : nullptr;
}

void ResourceManager::CleanUp()
{
	for(auto p : m_Resources)
	{
		delete p.second;
		p.second = nullptr;
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
}

void ResourceManager::LoadTexture(string name, string path)
{
	auto texture = new Texture();
	texture->loadFromFile(m_PathPrefix + path);

	m_Resources[name] = texture;
}
