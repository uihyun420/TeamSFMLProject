#pragma once
#include "Scene.h"
#include "CharacterInfo.h"
#include "BackgroundElement.h"
#include "TextGo.h"

class DuoCharacterSelectScene :
    public Scene
{
protected:

    enum class Choice { Choice01, Choice02 };
    Choice phase = Choice::Choice01;
    int selectedP1 = 0;
    int selectedP2 = 0;

    CharacterInfo* info = nullptr;


    std::vector<std::string> ids;
    std::vector<CharacterInfo*> charOptions;
    int selectedIndex = 0;

public:
    DuoCharacterSelectScene();

    void Init() override;
    void Update(float dt) override;
};
