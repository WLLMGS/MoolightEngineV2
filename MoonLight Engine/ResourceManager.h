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
	void CleanUp();
private:
	ResourceManager();
	void LoadTexture(string name, string path);
	
private:
	map<string, Texture*> m_Resources;
	string m_PathPrefix = "Resources/";

};

