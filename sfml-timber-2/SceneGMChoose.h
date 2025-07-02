#pragma once
#include "Scene.h"

class MenuUI;
class SpriteGo;

class SceneGMChoose : public Scene
{
protected:
	MenuUI* menuUI;

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

