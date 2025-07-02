#include "stdafx.h"
#include "UiHud.h"


UiHud::UiHud(const std::string& name)
	: GameObject(name)
{
}

void UiHud::SetLine(sf::Vector2f v, float f)
{
	line = sf::RectangleShape(v);
	line.setFillColor(sf::Color::Black);
	line.setPosition(FRAMEWORK.GetWindowSize().x / 2.f - f / 2.f, 0.f);
}

void UiHud::SetLineActive(bool b)
{
	lineActive = b;
}

void UiHud::SetType(ModeType t)
{
	type = t;
}

void UiHud::SetScore(int score)
{
	static std::string formatScore = "SCORE: ";
	textScore.setString(formatScore + std::to_string(score));
	Utils::SetOrigin(textScore, Origins::TL);
}

void UiHud::SetMessage(const std::string& msg)
{
	textMessage.setString(msg);
	Utils::SetOrigin(textMessage, Origins::MC);
}

void UiHud::SetTimeBar(float value)
{
	timeBar.setSize({ timeBarSize.x * value, timeBarSize.y });
}

void UiHud::SetTimeBarPos(const sf::Vector2f& v)
{
	timeBar.setPosition(v.x, v.y);
}

void UiHud::Init()
{
	fontId = "fonts/Galmuri11-Bold.ttf";

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	float thickness = 8.f;
	float length = FRAMEWORK.GetWindowSize().y;

	if(lineActive) SetLine({ thickness, length }, thickness);

	textScore.setCharacterSize(100);
	textScore.setFillColor(sf::Color::White);

	textMessage.setCharacterSize(100);
	textMessage.setFillColor(sf::Color::White);
	textMessage.setPosition(bounds.width * 0.5f, bounds.height * 0.5f);

	int w = FRAMEWORK.GetWindowSize().x / 2;
	textWin.setString("WIN!");
	Utils::SetOrigin(textWin, Origins::MC);
	textWin.setCharacterSize(100);
	textWin.setFillColor(sf::Color::White);
	textWin.setFillColor(sf::Color::White);
	textWin.setPosition(w / 2.f + 150.f, 20.f);

	textWin2.setString("WIN!");
	Utils::SetOrigin(textWin2, Origins::MC);
	textWin2.setCharacterSize(100);
	textWin2.setFillColor(sf::Color::White);
	textWin2.setFillColor(sf::Color::White);
	textWin2.setPosition(w + (w / 2.f) + 150.f, 20.f);

	timeBarSize = { 400.f, 80.f };
	timeBar.setFillColor(sf::Color::Red);
	timeBar.setSize(timeBarSize);

	Utils::SetOrigin(timeBar, Origins::BL);

	switch (type) {
	case ModeType::player1:
		textScore.setPosition(20, 20);
		timeBar.setPosition(bounds.width * 0.5f - timeBarSize.x * 0.5f, bounds.height - 100.f);
		break;
	case ModeType::player21:
		textScore.setPosition(20, 20);
		timeBar.setPosition(bounds.width * 0.5f * 0.5f - timeBarSize.x * 0.5f, bounds.height - 100.f);
		break;
	case ModeType::player22:
		textScore.setPosition(bounds.width / 2 + 20, 20);
		timeBar.setPosition(bounds.width * 0.5f + bounds.width * 0.5f * 0.5f - timeBarSize.x * 0.5f, bounds.height - 100.f);
		break;
	}
}

void UiHud::Release()
{
}

void UiHud::Reset()
{
	textScore.setFont(FONT_MGR.Get(fontId));
	textMessage.setFont(FONT_MGR.Get(fontId));
	textWin.setFont(FONT_MGR.Get(fontId));
	textWin2.setFont(FONT_MGR.Get(fontId));

	SetScore(0);
	isShowMessage = false;
	SetMessage("Message!");
	SetTimeBar(1.f);
}

void UiHud::Update(float dt)
{
}

void UiHud::Draw(sf::RenderWindow& window)
{
	window.draw(textScore);
	if (isShowMessage)
	{
		window.draw(textMessage);
	}
	window.draw(timeBar);
	if(lineActive) window.draw(line);
	if (isShowWin)
	{
		window.draw(textWin);
	}
	if (isShowWin2)
	{
		window.draw(textWin2);
	}
}
