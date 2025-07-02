#pragma once
#include "Scene.h"

class GameModeUI;
class SpriteGo;

class SceneDuoChoose : public Scene
{
protected:
	GameModeUI* gameModeUI;

	SpriteGo* classic;
	SpriteGo* challange;

public:
	SceneDuoChoose();
	~SceneDuoChoose() override;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

