#pragma once
#include "GameObject.h"
#include "TextGo.h"
class GameModeUI : public GameObject
{
protected:
	TextGo texts[2];
	sf::RectangleShape chooseBar;

	sf::Vector2f chooseBarSize = { 500.f, 100.f };
	std::vector<sf::Vector2f> textPos;
	std::vector<std::string> textMessages = { "1 Player","2 Player" };

	std::string fontId;

	int chooseBarPos = 0;
	int menuCount = 2;

public:
	GameModeUI(const std::string& name = "");
	~GameModeUI() override = default;

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

