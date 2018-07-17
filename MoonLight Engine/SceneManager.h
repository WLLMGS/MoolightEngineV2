#pragma once
class GameScene;


class SceneManager
{
public:
	static SceneManager* GetInstance()
	{
		static SceneManager instance;
		return &instance;
	}

	~SceneManager();

	void Update(float elapsedSec);
	void Render();
	void AddScene(GameScene* scene);
	void CleanUp();
	void NextScene();
	void GoToScene(string name);
private:
	SceneManager();

private:
	size_t m_ActiveScene = 0;
	vector<GameScene*> m_pScenes;
};

