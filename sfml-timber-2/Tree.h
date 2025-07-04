#pragma once
#include "GameObject.h"
class Tree : public GameObject
{
protected:
	sf::Sprite tree;
	std::vector<sf::Sprite> branches;
	std::vector<Sides> branchesSide;

	std::string texIdTree;
	std::string texIdBranch;

	bool isTwoPlayMode = false;

public:
	Tree() = default;
	~Tree() override = default;

	void SetTwoPlayMode(const bool& b);
	void SetPosition(const sf::Vector2f& pos) override;
	Sides UpdateBranches();

	Sides GetSide() const { return branchesSide[branchesSide.size() - 1]; }

	sf::Sprite GetSprite() const { return tree; }

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

