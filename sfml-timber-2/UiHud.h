#pragma once
#include "GameObject.h"
class UiHud : public GameObject
{
public:
	enum class ModeType
	{
		player1,
		player21,
		player22
	};

protected:
	sf::Text textScore;
	sf::Text textMessage;
	sf::Text textWin;
	sf::Text textWin2;
	sf::RectangleShape timeBar;

	sf::RectangleShape line;

	std::string fontId;
	bool isShowMessage;
	bool isShowWin = false;
	bool isShowWin2 = false;
	bool lineActive = false;

	sf::Vector2f timeBarSize;
    
	ModeType type = ModeType::player1;

public:
	UiHud(const std::string& name = "");
	~UiHud() override = default;

	void SetLine(sf::Vector2f v, float f);
	void SetLineActive(bool b);
	void SetType(ModeType t);

	sf::Vector2f gettimeBarSize() const { return timeBarSize; }

	void SetScore(int score);
	sf::Text GetTextWin() const { return textWin; }
	sf::Text GetTextScore() const { return textScore; }
	void SetMessage(const std::string& msg);
	void SetShowMassage(bool show) { isShowMessage = show; }
	void SetShowWin(bool show) { isShowWin = show; }
	void SetShowWin2(bool show) { isShowWin2 = show; }
	void SetTimeBar(float value); // 0.f ~ 1.f

	void SetTimeBarPos(const sf::Vector2f& v);

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

