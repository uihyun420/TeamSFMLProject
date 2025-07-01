#include "stdafx.h"
#include "GameOverUI.h"

GameOverUI::GameOverUI(const std::string& name)
	:GameObject(name)
{
}

void GameOverUI::Init()
{
	fontId = "fonts/KOMIKAP_.ttf";

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	textPos.push_back({ bounds.width * 0.5f, 550 });
	textPos.push_back({ bounds.width * 0.5f, 750 });

	restartText.SetCharacterSize(100);
	restartText.SetFillColor(sf::Color::White);
	restartText.SetPosition(textPos[0]);
	restartText.SetOrigin(Origins::MC);

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

void GameOverUI::Release()
{
}

void GameOverUI::Reset()
{
	restartText.GetText().setFont(FONT_MGR.Get(fontId));
	exitText.GetText().setFont(FONT_MGR.Get(fontId));

	restartText.SetString("Game Restart!");
	exitText.SetString("Exit Game");

	chooseBarPos = 0;
	chooseBar.setPosition(textPos[chooseBarPos] + sf::Vector2f{ 0.f, 25.f });
}

void GameOverUI::Update(float dt)
{
	chooseBar.setPosition(textPos[chooseBarPos] + sf::Vector2f{ 0.f, 25.f });
}

void GameOverUI::Draw(sf::RenderWindow& window)
{
	if (active)
	{
		restartText.Draw(window);
		exitText.Draw(window);
		window.draw(chooseBar);
	}
}
