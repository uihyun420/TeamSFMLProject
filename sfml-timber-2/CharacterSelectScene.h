#pragma once
#include "Scene.h"
#include "TextGo.h"
#include "CharacterInfo.h"

class CharacterSelectScene :
    public Scene
{
public:
    std::vector<CharacterInfo*> charOptions;
    int selectedIndex = 0;

public:
    CharacterSelectScene();

    void Init() override;
    void Update(float dt) override;
};

