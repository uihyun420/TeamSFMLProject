#include "stdafx.h"
#include "CharacterInfo.h"

CharacterInfo::CharacterInfo(const std::vector<std::string>& Ids,
                            const std::vector<sf::Vector2f>& pos)
	:texIds(Ids),positions(pos)
{
	icons.resize(texIds.size()); // icon�� ũ��
}

void CharacterInfo::Init()
{
    for (size_t i = 0; i < icons.size(); ++i)
    {
        // 1) �ؽ�ó ����
        icons[i].setTexture(TEXTURE_MGR.Get(texIds[i]));
        // 2) ���� ���� (�߾�)
        Utils::SetOrigin(icons[i], Origins::MC);
        // 3) ȭ�� ��ǥ ��ġ
        icons[i].setPosition(positions[i]);
    }
}

void CharacterInfo::Draw(sf::RenderWindow& window)
{
    for (auto& icon : icons)
        window.draw(icon);
}