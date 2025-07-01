#include "stdafx.h"
#include "CharacterInfo.h"

CharacterInfo::CharacterInfo(const std::vector<sf::String>& texIds, const std::vector<sf::Vector2f>& positions)
	:texIds(texIds),positions(positions)
{
}
