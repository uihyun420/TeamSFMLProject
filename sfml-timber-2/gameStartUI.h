#pragma once
#include "GameObject.h"
#include "TextGo.h"
class GameStartUI : public GameObject
{
protected:
	TextGo startText;
	TextGo exitText;
	sf::RectangleShape chooseBar;

	sf::Vector2f chooseBarSize = { 700.f, 100.f };
	sf::Vector2f startTextPos;
	sf::Vector2f exitTextPos;

	std::string fontId;

	int chooseBarPos = 0;

public:
	GameStartUI(const std::string& name = "");
	~GameStartUI() override = default;

	void setBarPos(int pos) { chooseBarPos = pos; }

	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

