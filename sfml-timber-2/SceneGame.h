#pragma once
#include "Scene.h"

class Player;
class Tree;
class UiHud;
class MenuUI;
class BackgroundElement;

class SceneGame : public Scene
{
protected:
	MenuUI* menuUI = nullptr;
	MenuUI* menuUI2 = nullptr;
	Player* player = nullptr;

	Tree* tree = nullptr;
	UiHud* uiHud = nullptr;

	std::vector <BackgroundElement*> Logs;

	bool isPlaying = false;
	int score = 0;
	float timer = 0.f;
	float timerMax = 5.f;

public:
	SceneGame();
	~SceneGame() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

	void CreateLog(Player* p);
};

