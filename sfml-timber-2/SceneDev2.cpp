#include "stdafx.h"
#include "SceneDev2.h"
#include "TextGo.h"

SceneDev2::SceneDev2()
	: Scene(SceneIds::DuoCharacterChoose)
{
}

void SceneDev2::Init()
{
	fontIds.push_back("fonts/Galmuri11-Bold.ttf");

	TextGo* go = new TextGo("fonts/Galmuri11-Bold.ttf");
	go->SetString("duo character choose scene");
	go->SetCharacterSize(30);
	go->SetFillColor(sf::Color::White);
	AddGameObject(go);

	Scene::Init();
}

void SceneDev2::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Player2Mode);
	}
}