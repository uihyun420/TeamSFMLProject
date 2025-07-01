#pragma once
#include "GameObject.h"
class CharacterInfo :
    public GameObject
{
protected:
    std::vector<sf::Sprite> icons; // ������
    std::vector<sf::Vector2f> positions; // ��ġ
    std::vector<std::string> texIds; // �ؽ��� Id

public:

    CharacterInfo(const std::vector<sf::String>& texIds,
                 const std::vector<sf::Vector2f>& positions);

    void Init() override;
    void Release() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
};

