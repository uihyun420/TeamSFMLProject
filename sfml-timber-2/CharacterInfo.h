#pragma once
#include "GameObject.h"
class CharacterInfo :
    public GameObject
{
protected:
    std::vector<sf::Sprite> player; // 플레이어 그림
    std::vector<sf::Vector2f> positions; // 위치
    std::vector<std::string> texIds; // 텍스쳐 Id

public:

    CharacterInfo(const std::vector<std::string>& ids, const std::vector<sf::Vector2f>& pos); // Id와 위치 생성자
    ~CharacterInfo() = default;


    void SetIconColor(std::size_t idx, const sf::Color& color);
    void SetIconScale(std::size_t idx, const sf::Vector2f& scale);


    void Init() override;
    void Release() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
};

