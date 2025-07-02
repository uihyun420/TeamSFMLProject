#include "stdafx.h"
#include "CharacterSelectScene.h"
#include "CharacterInfo.h"
#include "BackgroundElement.h"


CharacterSelectScene::CharacterSelectScene()
	:Scene(SceneIds::CharacterSelect)
{
}



void CharacterSelectScene::Init()
{
	texIds.push_back("graphics/background1.png");
	
	AddGameObject(new SpriteGo("graphics/background1.png"));

	texIds.push_back("graphics/player.png");
	texIds.push_back("graphics/player2.png");
	fontIds.push_back("fonts/KOMIKAP_.ttf");


	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetString("Character Select");
	go->SetCharacterSize(100);
	go->SetFillColor(sf::Color::White);
	go->SetOrigin(Origins::MC);

	TextGo* go1 = new TextGo("fonts/KOMIKAP_.ttf");
	go1->SetString("Player 1P");
	go1->SetCharacterSize(50);
	go1->SetFillColor(sf::Color::Black);
	go1->SetOrigin(Origins::MC);

	TextGo* go2 = new TextGo("fonts/KOMIKAP_.ttf");
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



	std::vector<std::string> ids = 
	{
	"graphics/player.png",
	"graphics/player2.png"
	};

	std::vector<sf::Vector2f> pos = 
	{
		{660.f, 520.f},
		{1260.f, 520.f}
	};

	info = new CharacterInfo(ids, pos);
	AddGameObject(info);


	
	Scene::Init();
}



void CharacterSelectScene::Update(float dt)
{	
	//int& select = (phase == Choice::Choice01 ? selectedP1 : selectedP2);


	//if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	//{
	//	select = (select +ids .size() -1)% ids.size();
	//}
	//if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	//{
	//	select = (select +ids.size() + 1) % ids.size();
	//}


	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
}