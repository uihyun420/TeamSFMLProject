#pragma once
#include "Scene.h"
#include "CharacterInfo.h"
#include "BackgroundElement.h"
#include "TextGo.h"

class TextGo;

class DuoCharacterSelectScene :
    public Scene
{
protected:

    TextGo* go1;
    TextGo* go2;

    enum class Choice { Choice01, Choice02, Choice03, Choice04 };
    Choice phase = Choice::Choice01;
    int selectedP1 = 0;
    int selectedP2 = 0;
    int selectedP3 = 0;
    int selectedP4 = 0;

    CharacterInfo* info = nullptr;

    std::vector<sf::Vector2f> choosePos;

    std::vector<std::string> ids;
    std::vector<CharacterInfo*> charOptions;
    int selectedIndex = 0;

public:
    DuoCharacterSelectScene();

    void Init() override;
    void Update(float dt) override;
};
