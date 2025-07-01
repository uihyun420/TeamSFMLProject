#pragma once
#include "Scene.h"

class Player;
class Tree;
class GameStartUI;

class SceneStart :public Scene
{
protected:
	Player* player;
	Tree* tree[3];
	GameStartUI* startUI;

public:
	SceneStart();
	~SceneStart() override;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

