#pragma once
#include "GameObject.h"
#include "TextGo.h"
class MenuUI : public GameObject
{
protected:
	TextGo* texts;
	int menuCount = 0;

public:
	MenuUI(const std::string& name);
	~MenuUI() override = default;

	void SetMenuUI(int count);

	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

