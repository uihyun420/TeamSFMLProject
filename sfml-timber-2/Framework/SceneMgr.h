#pragma once
class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

protected:
	SceneMgr() = default;
	~SceneMgr() = default;

	std::vector<Scene*> scenes;

	SceneIds startScene = SceneIds::GameStart;
	SceneIds currentScene = SceneIds::None;
	SceneIds nextScene = SceneIds::None;

public:

	std::string chosenChar1; // 1p / 2p가 고른 텍스처 경로를 저장할 변수
	std::string chosenChar2;

	void Init();
	void Release();

	Scene* GetCurrentScene() { return scenes[(int)currentScene]; }
	SceneIds GetCurrentSceneId() const { return currentScene; }
	void ChangeScene(SceneIds id);

	void Update(float dt);
	void Draw(sf::RenderWindow& window);



	void SetChosenChar1(const std::string& s);
	void SetChosenChar2(const std::string& s);
	const std::string& GetChosenChar1();
	const std::string& GetChosenChar2();


};

#define SCENE_MGR (SceneMgr::Instance())

