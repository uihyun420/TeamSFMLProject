#pragma once
class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

protected:
	SceneMgr() = default;
	~SceneMgr() = default;

	std::vector<Scene*> scenes;

	SceneIds startScene = SceneIds::ChallangeMode;
	SceneIds currentScene = SceneIds::None;
	SceneIds nextScene = SceneIds::None;

	SceneIds duomode = SceneIds::None;
	bool isDuo = false;

public:
	void Init();
	void Release();

	Scene* GetCurrentScene() { return scenes[(int)currentScene]; }
	SceneIds GetCurrentSceneId() const { return currentScene; }
	void ChangeScene(SceneIds id, bool duo = false, SceneIds next = SceneIds::None);
	bool GetIsDuo() const {return isDuo;}
	SceneIds GetDuoModeScene() const {return duomode;}

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

#define SCENE_MGR (SceneMgr::Instance())

