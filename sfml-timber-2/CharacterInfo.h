#pragma once
#include "GameObject.h"
class CharacterInfo :
    public GameObject
{
protected:
    std::vector<sf::Sprite> icons; // 아이콘
    std::vector<sf::Vector2f> positions; // 위치
    std::vector<std::string> texIds; // 텍스쳐 Id

public:

    CharacterInfo(const std::vector<sf::String>& texIds,
                 const std::vector<sf::Vector2f>& positions);

    void Init() override;
    void Release() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
};

