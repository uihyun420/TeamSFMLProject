#pragma once
class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

protected:
	SceneMgr() = default;
	~SceneMgr() = default;

	std::vector<Scene*> scenes;

	SceneIds startScene = SceneIds::GameStart;
	SceneIds startScene = SceneIds::ChallangeMode;
	SceneIds currentScene = SceneIds::None;
	SceneIds nextScene = SceneIds::None;

	SceneIds sId = SceneIds::None;
	std::string texId = "graphics/player.png";
	std::string texId2 = "graphics/player2.png";
	bool isDuo = false;

	SceneIds duomode = SceneIds::None;
	bool isDuo = false;

public:
	void Init();
	void Release();

	Scene* GetCurrentScene() { return scenes[(int)currentScene]; }
	SceneIds GetCurrentSceneId() const { return currentScene; }
	void ChangeScene(SceneIds id);

	void setScene(SceneIds id) { sId = id; }
	SceneIds getScene() const { return sId; }

	void setTexId(const std::string& s, bool solo = false, const std::string& duo = "");
	std::string getTexId() const { return texId; }
	std::string getDuoTexId() const { return texId2; }

	bool GetDuo() const { return isDuo; }
	void SetDuo(bool b) { isDuo = b; }
	void ChangeScene(SceneIds id, bool duo = false, SceneIds next = SceneIds::None);
	bool GetIsDuo() const {return isDuo;}
	SceneIds GetDuoModeScene() const {return duomode;}

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

#define SCENE_MGR (SceneMgr::Instance())

