#include "stdafx.h"
#include "SceneDev3.h"
#include "TextGo.h"

SceneDev3::SceneDev3()
	:Scene(SceneIds::Player2Mode)
{
}

void SceneDev3::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetString("Duo player Mode");
	go->SetCharacterSize(30);
	go->SetFillColor(sf::Color::White);
	AddGameObject(go);

	Scene::Init();
}

void SceneDev3::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::GameStart);
	}
}
