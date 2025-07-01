#pragma once
#include "Scene.h"
#include "TextGo.h"

class CharacterSelectScene :
    public Scene
{
public:
    CharacterSelectScene();

    void Init() override;
    void Update(float dt) override;
};

