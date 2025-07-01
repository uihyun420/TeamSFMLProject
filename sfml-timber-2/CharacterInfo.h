#pragma once
#include "GameObject.h"
class CharacterInfo :
    public GameObject
{
protected:
    std::vector<sf::Sprite> player; // �÷��̾� �׸�
    std::vector<sf::Vector2f> positions; // ��ġ
    std::vector<std::string> texIds; // �ؽ��� Id

public:

    CharacterInfo(const std::vector<std::string>& ids, const std::vector<sf::Vector2f>& pos); // Id�� ��ġ ������
    ~CharacterInfo() = default;


    void Init() override;
    void Release() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
};

