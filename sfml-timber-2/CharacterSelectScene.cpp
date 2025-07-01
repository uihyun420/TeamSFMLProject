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
	go->SetCharacterSize(50);
	go->SetFillColor(sf::Color::White);
	AddGameObject(go);


	Scene::Init();
}

void CharacterSelectScene::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
}