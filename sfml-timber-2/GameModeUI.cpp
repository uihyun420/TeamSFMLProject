#include "stdafx.h"
#include "GameModeUI.h"

GameModeUI::GameModeUI(const std::string& name)
	:GameObject(name)
{
}

void GameModeUI::SetTextMessages(std::vector<std::string> messages)
{
	for (int i = 0; i < menuCount; i++)
	{
		textMessages[i] = messages[i];

	}
}

void GameModeUI::Init()
{
	fontId = "fonts/Galmuri11-Bold.ttf";

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	textPos.push_back({ bounds.width * 0.5f - 450.f, 800.f });
	textPos.push_back({ bounds.width * 0.5f + 450.f, 800.f });

	for (int i = 0; i < menuCount; i++)
	{
		texts[i].SetCharacterSize(100);
		texts[i].SetFillColor(sf::Color::White);
		texts[i].SetPosition(textPos[i]);
		texts[i].SetOrigin(Origins::MC);
	}

	chooseBar.setFillColor(sf::Color(0, 0, 0, 0));
	chooseBar.setOutlineColor(sf::Color::Yellow);
	chooseBar.setOutlineThickness(5.f);
	chooseBar.setSize(chooseBarSize);
	Utils::SetOrigin(chooseBar, Origins::MC);
}

void GameModeUI::Release()
{
}

void GameModeUI::Reset()
{
	for (int i = 0; i < menuCount; i++)
	{
		texts[i].GetText().setFont(FONT_MGR.Get(fontId));
		texts[i].SetString(textMessages[i]);
	}

	chooseBarPos = 0;
	chooseBar.setPosition(textPos[chooseBarPos] + sf::Vector2f{ 0.f, 15.f });
}

void GameModeUI::Update(float dt)
{
	chooseBar.setPosition(textPos[chooseBarPos] + sf::Vector2f{ 0.f, 15.f });
	for (int i = 0; i < menuCount; i++)
	{
		if (i == chooseBarPos)
		{
			texts[i].SetFillColor(sf::Color::Yellow);
		}
		else
		{
			texts[i].SetFillColor(sf::Color::White);
		}
	}
}

void GameModeUI::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < menuCount; i++)
	{
		texts[i].Draw(window);
	}
	window.draw(chooseBar);
}
