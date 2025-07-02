#include "stdafx.h"
#include "SceneDuoChoose.h"
#include "SpriteGo.h"
#include "GameModeUI.h"

SceneDuoChoose::SceneDuoChoose()
	:Scene(SceneIds::DuoMode)
{
}

SceneDuoChoose::~SceneDuoChoose()
{
}

void SceneDuoChoose::Init()
{
	texIds.push_back("graphics/mainbackground.png");
	texIds.push_back("graphics/duomode.png");

	fontIds.push_back("fonts/Galmuri11-Bold.ttf");

	AddGameObject(new SpriteGo("graphics/mainbackground.png"));

	classic = (SpriteGo*)AddGameObject(new SpriteGo("graphics/duomode.png"));
	classic->SetOrigin(Origins::MC);
	challange = (SpriteGo*)AddGameObject(new SpriteGo("graphics/duomode.png"));
	challange->SetOrigin(Origins::MC);

	gameModeUI = (GameModeUI*)AddGameObject(new GameModeUI());
	gameModeUI->SetChooseBarSize({ 700.f,130.f });
	gameModeUI->SetTextMessages({"Classic","Challange"});

	Scene::Init();
}

void SceneDuoChoose::Enter()
{
	Scene::Enter();

	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();

	classic->SetScale({ 0.4f,0.4f });
	classic->SetPosition({ bound.width / 2.f - 450.f, 400.f });

	challange->SetScale({ 0.4f,0.4f });
	challange->SetPosition({ bound.width / 2.f + 450.f, 400.f });
}

void SceneDuoChoose::Exit()
{
	Scene::Exit();
}

void SceneDuoChoose::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Left) || InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		gameModeUI->SetBarPos((gameModeUI->GetBarPos() + 1) % gameModeUI->GetMenuCount());
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && !gameModeUI->GetBarPos())
	{
		//SCENE_MGR.ChangeScene(SceneIds::Player1Mode);
		SCENE_MGR.ChangeScene(SceneIds::DuoCharacterChoose);
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && gameModeUI->GetBarPos())
	{
		//SCENE_MGR.ChangeScene(SceneIds::Player2Mode);
		SCENE_MGR.ChangeScene(SceneIds::DuoCharacterChoose);
	}
}