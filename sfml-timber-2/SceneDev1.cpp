#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"

SceneDev1::SceneDev1()
	: Scene(SceneIds::SoloCharacterChoose)
{
}

void SceneDev1::Init()
{
	fontIds.push_back("fonts/Galmuri11-Bold.ttf");

	TextGo* go = new TextGo("fonts/Galmuri11-Bold.ttf");
	go->SetString("Solo character choose scene");
	go->SetCharacterSize(30);
	go->SetFillColor(sf::Color::White);
	AddGameObject(go);

	Scene::Init();
}

void SceneDev1::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Player1Mode);
	}
}
