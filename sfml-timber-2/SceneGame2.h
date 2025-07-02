#pragma once
#include "Scene.h"

class Player;
class Tree;
class UiHud;
class GameOverUI;
class BackgroundElement;
class MenuUI;

class SceneGame2 : public Scene
{
protected:
	GameOverUI* overUI = nullptr;
	Player* player = nullptr;
	Player* player2 = nullptr;

	Tree* tree = nullptr;
	Tree* tree2 = nullptr;

	UiHud* uiHud = nullptr;
	UiHud* uiHud2 = nullptr;

	MenuUI* menuUI;

	std::vector <BackgroundElement*> Logs;

	bool isPlaying = false;
	float bgTime = 0.f;
	int score = 0;
	int score2 = 0;
	float timer = 0.f;
	float timer2 = 0.f;
	float timerMax = 5.f;

	enum class Menu
	{
		home,
		restart,
		exit
	};

public:
	SceneGame2();
	~SceneGame2() override;


	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

	void CreateLog(Player* p);
};

