#pragma once
#include "Scene.h"

class GameStartUI;

class SceneStart :public Scene
{
protected:
	GameStartUI* startUI;

public:
	SceneStart();
	~SceneStart() override;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

