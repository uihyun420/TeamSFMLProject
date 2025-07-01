#include "stdafx.h"
#include "GameStartUI.h"

GameStartUI::GameStartUI(const std::string& name)
	:GameObject(name)
{
}

void GameStartUI::Init()
{
	fontId = "fonts/KOMIKAP_.ttf";

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	textPos.push_back({ bounds.width * 0.5f, 550 });
	textPos.push_back({ bounds.width * 0.5f, 750 });

	startText.SetCharacterSize(100);
	startText.SetFillColor(sf::Color::White);
	startText.SetPosition(textPos[0]);
	startText.SetOrigin(Origins::MC);

	exitText.SetCharacterSize(100);
	exitText.SetFillColor(sf::Color::White);
	exitText.SetPosition(textPos[1]);
	exitText.SetOrigin(Origins::MC);

	chooseBar.setFillColor(sf::Color(0, 0, 0, 0));
	chooseBar.setOutlineColor(sf::Color::White);
	chooseBar.setOutlineThickness(3.f);
	chooseBar.setSize(chooseBarSize);
	Utils::SetOrigin(chooseBar, Origins::MC);
}

void GameStartUI::Release()
{
}

void GameStartUI::Reset()
{
	startText.GetText().setFont(FONT_MGR.Get(fontId));
	exitText.GetText().setFont(FONT_MGR.Get(fontId));

	startText.SetString("Game Start!");
	exitText.SetString("Exit Game!");

	chooseBarPos = 0;
	chooseBar.setPosition(textPos[chooseBarPos] + sf::Vector2f{ 0.f, 25.f});
}

void GameStartUI::Update(float dt)
{
	chooseBar.setPosition(textPos[chooseBarPos] + sf::Vector2f{ 0.f, 25.f });
}

void GameStartUI::Draw(sf::RenderWindow& window)
{
	startText.Draw(window);
	exitText.Draw(window);
	window.draw(chooseBar);
}

