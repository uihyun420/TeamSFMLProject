#pragma once
#include "Scene.h"
class SceneDev3 : public Scene
{
protected:

public:
	SceneDev3();

	void Init() override;
	void Update(float dt) override;
};

