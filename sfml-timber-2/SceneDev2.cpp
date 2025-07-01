#include "stdafx.h"
#include "SceneDev2.h"
#include "TextGo.h"

SceneDev2::SceneDev2()
	: Scene(SceneIds::Dev2)
{
}

void SceneDev2::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetString("Dev 2");
	go->SetCharacterSize(30);
	go->SetFillColor(sf::Color::White);
	AddGameObject(go);

	Scene::Init();
}

void SceneDev2::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}
}