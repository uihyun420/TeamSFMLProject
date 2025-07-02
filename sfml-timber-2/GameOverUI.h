#pragma once
#include "GameObject.h"
#include "TextGo.h"
class GameOverUI : public GameObject
{
protected:
	TextGo texts[3];
	
	sf::RectangleShape chooseBar;

	sf::Vector2f chooseBarSize = { 800.f, 130.f };
	std::vector<sf::Vector2f> textPos;
	std::vector<std::string> textMessages = { "Go to main!", "Game Restart!", "Exit Game" };

	std::string fontId;

	int chooseBarPos = 1;
	int menuCount = 3;

public:
	GameOverUI(const std::string& name = "");
	~GameOverUI() override = default;

	void SetBarPos(int pos) { chooseBarPos = pos; }
	int GetBarPos() const { return chooseBarPos; }

	int GetMenuCount() const { return menuCount; }

	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

