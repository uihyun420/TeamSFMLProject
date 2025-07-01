#pragma once
#include "Scene.h"

class Player;
class Tree;
class GameModeUI;
class SpriteGo;

class SceneGMChoose : public Scene
{
protected:
	Player* player;
	Tree* tree[3];
	GameModeUI* gameModeUI;

	SpriteGo* solo;
	SpriteGo* duo;

public:
	SceneGMChoose();
	~SceneGMChoose() override;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

