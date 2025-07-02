#pragma once
#include "Scene.h"

class MenuUI;

class SceneStart :public Scene
{
protected:
	MenuUI* menuUI;

public:
	SceneStart();
	~SceneStart() override;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

