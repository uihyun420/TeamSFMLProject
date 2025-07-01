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
	startTextPos = { bounds.width * 0.5f, 550 };
	exitTextPos = { bounds.width * 0.5f, 750 };

	startText.SetCharacterSize(100);
	startText.SetFillColor(sf::Color::White);
	startText.SetPosition(startTextPos);
	startText.SetOrigin(Origins::MC);

	exitText.SetCharacterSize(100);
	exitText.SetFillColor(sf::Color::White);
	exitText.SetPosition(exitTextPos);
	exitText.SetOrigin(Origins::MC);

	chooseBar.setFillColor(sf::Color(0,0,0,0));
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

	chooseBar.setPosition(startTextPos + sf::Vector2f{0.f, 25.f});
}

void GameStartUI::Update(float dt)
{
}

void GameStartUI::Draw(sf::RenderWindow& window)
{
	startText.Draw(window);
	exitText.Draw(window);
	window.draw(chooseBar);
}

