#include "stdafx.h"
#include "GameModeUI.h"

GameModeUI::GameModeUI(const std::string& name)
	:GameObject(name)
{
}

void GameModeUI::Init()
{
	fontId = "fonts/KOMIKAP_.ttf";

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	textPos.push_back({ bounds.width * 0.5f - 400.f, 800 });
	textPos.push_back({ bounds.width * 0.5f + 400.f, 800 });

	soloText.SetCharacterSize(100);
	soloText.SetFillColor(sf::Color::White);
	soloText.SetPosition(textPos[0]);
	soloText.SetOrigin(Origins::MC);

	duoText.SetCharacterSize(100);
	duoText.SetFillColor(sf::Color::White);
	duoText.SetPosition(textPos[1]);
	duoText.SetOrigin(Origins::MC);

	chooseBar.setFillColor(sf::Color(0, 0, 0, 0));
	chooseBar.setOutlineColor(sf::Color::White);
	chooseBar.setOutlineThickness(3.f);
	chooseBar.setSize(chooseBarSize);
	Utils::SetOrigin(chooseBar, Origins::MC);
}

void GameModeUI::Release()
{
}

void GameModeUI::Reset()
{
	soloText.GetText().setFont(FONT_MGR.Get(fontId));
	duoText.GetText().setFont(FONT_MGR.Get(fontId));

	soloText.SetString("1 Player");
	duoText.SetString("2 Player");

	chooseBarPos = 0;
	chooseBar.setPosition(textPos[chooseBarPos] + sf::Vector2f{ 0.f, 25.f });
}

void GameModeUI::Update(float dt)
{
	chooseBar.setPosition(textPos[chooseBarPos] + sf::Vector2f{ 0.f, 25.f });
}

void GameModeUI::Draw(sf::RenderWindow& window)
{
	soloText.Draw(window);
	duoText.Draw(window);
	window.draw(chooseBar);
}
