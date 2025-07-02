#pragma once
#include "Scene.h"

class Player;
class Tree;
class UiHud;
class BackgroundElement;
class MenuUI;

class SceneGame3 : public Scene
{
protected:
	Player* player;
	Player* player2;

	Tree* tree;
	UiHud* uiHud;
	UiHud* uiHud2;
	MenuUI* menuUI;
	MenuUI* menuUI2;

	BackgroundElement* beeElement;

	std::vector <BackgroundElement*> Logs;

	bool isPlaying = false;
	float bgTime = 0.f;
	int score = 0;
	int score2 = 0;
	float timer = 0.f;
	float timer2 = 0.f;
	float timerMax = 5.f;

	float player1Speed = 1000.f;
	float player2Speed = 1000.f;
	float playerInitSpeed = 1000.f;
	float gravity = 1000.f;

public:
	SceneGame3();
	~SceneGame3() override;


	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

	void CreateLog(Player* p);
};

