#pragma once
#include "Scene.h"
#include <SFML/Audio.hpp>

class MenuUI;

class SceneStart :public Scene
{
protected:
	MenuUI* menuUI;

	sf::Music bgm;
	float bgmVolume = 100.f;



public:
	SceneStart();
	~SceneStart() override;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

