#pragma once
#include "GameObject.h"

class Player : public GameObject
{
protected:
	sf::Sprite sprite;
	sf::Sprite axe;

	Sides side = Sides::Right;

	std::vector<sf::Vector2f> positions;
	std::vector<sf::Vector2f> scales;
	std::vector<sf::Vector2f> axePositions;

	std::string texPlayerId;
	std::string ripTexId;
	std::string axeTexId;

	bool isAlive = true;
	bool drawAxe = false;

public:
	Player(const std::string& name = "");
	~Player() override = default;
	
	void SetAlive(bool alive);
	bool GetAlive() const { return isAlive; }
	void SetDrawAxe(bool draw) { drawAxe = draw; }
	bool GetDrawAxe() const { return drawAxe; }

	sf::Sprite& GetSprite() { return sprite; }

	void SetTexId(const std::string& id);

	void SetSide(Sides s);
	Sides GetSide() const { return side; }

	void SetScale(const sf::Vector2f& scale) override;

	void SetPosition(const sf::Vector2f& pos) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

