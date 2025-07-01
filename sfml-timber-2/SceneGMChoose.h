#pragma once
#include "Scene.h"

class Player;
class Tree;
class GameModeUI;

class SceneGMChoose : public Scene
{
protected:
	Player* player;
	Tree* tree[3];
	GameModeUI* gameModeUI;

public:
	SceneGMChoose();
	~SceneGMChoose() override;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

