#pragma once
class ResourceManager
{
public:
	static ResourceManager* GetInstance()
	{
		static ResourceManager instance;

		return &instance;
	}
	~ResourceManager();
	Texture* RequestTexture(string name);
	Font* RequestFont(string name);
	void CleanUp();
private:
	ResourceManager();
	void LoadTexture(string name, string path);
	void LoadFont(string name, string path);
private:
	map<string, Texture*> m_Resources;
	map<string, Font*> m_Fonts;
	string m_PathPrefix = "Resources/";

};

