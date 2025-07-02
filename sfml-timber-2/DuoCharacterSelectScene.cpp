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
	texIds.push_back("graphics/player3.png");
	texIds.push_back("graphics/player4.png");

	fontIds.push_back("fonts/Galmuri11-Bold.ttf");


	TextGo* go = new TextGo("fonts/Galmuri11-Bold.ttf");
	go->SetString("Character Select");
	go->SetCharacterSize(100);
	go->SetFillColor(sf::Color::White);
	go->SetOrigin(Origins::MC);

	go1 = new TextGo("fonts/Galmuri11-Bold.ttf");
	go1->SetString("1P");
	go1->SetCharacterSize(50);
	go1->SetFillColor(sf::Color::Black);
	go1->SetOrigin(Origins::MC);

	go2 = new TextGo("fonts/Galmuri11-Bold.ttf");
	go2->SetString("2P");
	go2->SetCharacterSize(50);
	go2->SetFillColor(sf::Color::Black);
	go2->SetOrigin(Origins::MC);

	auto bounds = FRAMEWORK.GetWindowBounds();
	choosePos = {
		{ bounds.width * 0.2f, 720.f },
		{ bounds.width * 0.4f, 720.f },
		{ bounds.width * 0.6f, 720.f },
		{ bounds.width * 0.8f, 720.f }
	};
	go->SetPosition({ bounds.width * 0.5f, 150.f });
	AddGameObject(go);

	go1->SetPosition(choosePos[0]);
	AddGameObject(go1);

	go2->SetPosition(choosePos[1]);
	AddGameObject(go2);


	ids = { "graphics/player.png",	"graphics/player2.png", "graphics/player3.png", "graphics/player4.png" };

	std::vector<sf::Vector2f> pos =
	{
		{bounds.width * 0.2f, 520.f},
		{bounds.width * 0.4f, 520.f},
		{bounds.width * 0.6f, 520.f},
		{bounds.width * 0.8f, 520.f}
	};

	info = new CharacterInfo(ids, pos);
	AddGameObject(info);

	Scene::Init();
}



void DuoCharacterSelectScene::Update(float dt)
{
	int& select = selectedP1;
	int& select2 = selectedP2;


	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		select = (select + ids.size() - 1) % ids.size();
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		select = (select + ids.size() + 1) % ids.size();
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::A))
	{
		select2 = (select2 + ids.size() - 1) % ids.size();
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::D))
	{
		select2 = (select2 + ids.size() + 1) % ids.size();
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		SCENE_MGR.ChangeScene(SCENE_MGR.getScene());
		SCENE_MGR.setTexId(ids[select], true, ids[select2]);
	} 
	else if (InputMgr::GetKeyDown(sf::Keyboard::BackSpace))
	{
		//SCENE_MGR.ChangeScene(SceneIds::Player2Mode);
		SCENE_MGR.ChangeScene(SceneIds::DuoMode);
	}
	go1->SetPosition(choosePos[select]);
	go2->SetPosition(choosePos[select2]);

	if (select == select2)
	{
		go2->SetPosition(go2->GetPosition() + sf::Vector2f({ 0.f, 50.f }));
	}

}