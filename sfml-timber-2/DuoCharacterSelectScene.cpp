#include "stdafx.h"
#include "DuoCharacterSelectScene.h"
#include "CharacterInfo.h"
#include "BackgroundElement.h"

DuoCharacterSelectScene::DuoCharacterSelectScene()
	:Scene(SceneIds::DuoCharacterChoose)
{
}

void DuoCharacterSelectScene::Init()
{
	texIds.push_back("graphics/mainbackground.png");

	AddGameObject(new SpriteGo("graphics/mainbackground.png"));

	texIds.push_back("graphics/player.png");
	texIds.push_back("graphics/player2.png");
	fontIds.push_back("fonts/Galmuri11-Bold.ttf");


	TextGo* go = new TextGo("fonts/Galmuri11-Bold.ttf");
	go->SetString("Character Select");
	go->SetCharacterSize(100);
	go->SetFillColor(sf::Color::White);
	go->SetOrigin(Origins::MC);

	TextGo* go1 = new TextGo("fonts/Galmuri11-Bold.ttf");
	go1->SetString("Player 1P");
	go1->SetCharacterSize(50);
	go1->SetFillColor(sf::Color::Black);
	go1->SetOrigin(Origins::MC);

	TextGo* go2 = new TextGo("fonts/Galmuri11-Bold.ttf");
	go2->SetString("Player 2P");
	go2->SetCharacterSize(50);
	go2->SetFillColor(sf::Color::Black);
	go2->SetOrigin(Origins::MC);


	auto bounds = FRAMEWORK.GetWindowBounds();
	go->SetPosition({ bounds.width * 0.5f, 150.f });
	AddGameObject(go);


	go1->SetPosition({ 660.f, 720.f });
	AddGameObject(go1);

	go2->SetPosition({ 1260.f, 720.f });
	AddGameObject(go2);



	ids = { "graphics/player.png",	"graphics/player2.png" };

	std::vector<sf::Vector2f> pos =
	{
		{660.f, 520.f},
		{1260.f, 520.f}
	};

	info = new CharacterInfo(ids, pos);
	AddGameObject(info);



	Scene::Init();
}



void DuoCharacterSelectScene::Update(float dt)
{
	int& select = (phase == Choice::Choice01 ? selectedP1 : selectedP2);


	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		select = (select + ids.size() - 1) % ids.size();
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		select = (select + ids.size() + 1) % ids.size();
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		bool isDuo = SCENE_MGR.GetIsDuo();
		if (isDuo)
			SCENE_MGR.ChangeScene(SCENE_MGR.GetDuoModeScene());
	}

	for (std::size_t i = 0; i < ids.size(); ++i)
	{
		bool isActive = (phase == Choice::Choice01 && i == selectedP1) || (phase == Choice::Choice02 && i == selectedP2);

		// 스케일 업/다운
		info->SetIconScale(i, isActive ? sf::Vector2f{ 1.3f,1.3f } : sf::Vector2f{ 1.f,1.f }); // 선택된 것은 130%의 크기로

	}

}