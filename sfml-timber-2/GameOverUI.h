#pragma once
#include "GameObject.h"
#include "TextGo.h"
class GameOverUI : public GameObject
{
protected:
	TextGo restartText;
	TextGo exitText;
	sf::RectangleShape chooseBar;

	sf::Vector2f chooseBarSize = { 800.f, 100.f };
	std::vector<sf::Vector2f> textPos;

	std::string fontId;

	int chooseBarPos = 0;
	int menuCount = 2;

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

