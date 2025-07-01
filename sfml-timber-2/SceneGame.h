#pragma once
#include "Scene.h"

class Player;
class Tree;
class UiHud;
class BackgroundElement;

class SceneGame : public Scene
{
protected:
	Player* player;
	Player* player2;

	Tree* tree;
	UiHud* uiHud;

	std::vector <BackgroundElement*> Logs;

	bool isPlaying = false;
	int score = 0;
	int score2 = 0;
	float timer = 0.f;
	float timer2 = 0.f;
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

