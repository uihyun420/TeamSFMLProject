#include "stdafx.h"
#include "CharacterSelectScene.h"
#include "CharacterInfo.h"



CharacterSelectScene::CharacterSelectScene()
	:Scene(SceneIds::CharacterSelect)
{
}



void CharacterSelectScene::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");
	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetString("Character Select");
	go->SetCharacterSize(100);
	go->GetPosition( );
	go->SetFillColor(sf::Color::Red);
	AddGameObject(go);


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

	CharacterInfo* info = new CharacterInfo(ids, pos);
	AddGameObject(info);
	charOptions.push_back(info);

	
	Scene::Init();
}



void CharacterSelectScene::Update(float dt)
{

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
}