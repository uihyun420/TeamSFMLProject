#pragma once
#include "GameObject.h"
#include "TextGo.h"
class GameStartUI : public GameObject
{
protected:
	TextGo texts[2];
	sf::RectangleShape chooseBar;

	sf::Vector2f chooseBarSize = { 700.f, 130.f };
	std::vector<sf::Vector2f> textPos;
	std::vector<std::string> textMessages = { "Game Start!", "Exit Game!" };

	std::string fontId;

	int chooseBarPos = 0;
	int menuCount = 2;

public:
	GameStartUI(const std::string& name = "");
	~GameStartUI() override = default;

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

