#include "stdafx.h"
#include "CharacterInfo.h"



CharacterInfo::CharacterInfo(const std::vector<std::string>& ids, const std::vector<sf::Vector2f>& pos)
    : texIds(ids) , positions(pos)
{
    
}

void CharacterInfo::Init()
{
    for (size_t i = 0; i < player.size(); ++i) 
    {
        player[i].setTexture(TEXTURE_MGR.Get(texIds[i]));
        Utils::SetOrigin(player[i], Origins::MC);
        player[i].setPosition(positions[i]);
    }
    player.resize(texIds.size());

}

void CharacterInfo::Draw(sf::RenderWindow& window)
{
    for (auto& player : player)
        window.draw(player);
}

void CharacterInfo::Release()
{

}

void CharacterInfo::Reset()
{
    for (size_t i = 0; i < player.size(); ++i)
    {
        player[i].setTexture(TEXTURE_MGR.Get(texIds[i]));
        Utils::SetOrigin(player[i], Origins::MC);
        player[i].setPosition(positions[i]);
    }
}

void CharacterInfo::Update(float dt)
{
    // 선택 상태를 관리하려면 여기에 로직 추가
}