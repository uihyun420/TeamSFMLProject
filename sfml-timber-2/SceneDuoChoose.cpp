#include "stdafx.h"
#include "SceneDuoChoose.h"
#include "SpriteGo.h"
#include "MenuUI.h"

int mode = 0;

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
	texIds.push_back("graphics/challange.png");

	fontIds.push_back("fonts/Galmuri11-Bold.ttf");

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	AddGameObject(new SpriteGo("graphics/mainbackground.png"));

	classic = (SpriteGo*)AddGameObject(new SpriteGo("graphics/duomode.png"));
	classic->SetOrigin(Origins::MC);
	challange = (SpriteGo*)AddGameObject(new SpriteGo("graphics/challange.png"));
	challange->SetOrigin(Origins::MC);

	menuUI = (MenuUI*)AddGameObject(new MenuUI());

	menuUI->SetFontId("fonts/Galmuri11-Bold.ttf");

	menuUI->AddMessages("Classic");
	menuUI->AddMessages("Challange");

	menuUI->AddTextPos({ bounds.width * 0.5f - 450.f, 800.f });
	menuUI->AddTextPos({ bounds.width * 0.5f + 450.f, 800.f });

	for (int i = 0; i < menuUI->GetMenuCount(); i++)
	{
		TextGo text;
		text.SetCharacterSize(100);
		text.SetFillColor(sf::Color::White);
		text.SetPosition(menuUI->GetTextPos()[i]);
		text.SetOrigin(Origins::MC);
		menuUI->AddTextGo(text);
	}

	menuUI->SetChooseBarColor(sf::Color(0, 0, 0, 0));
	menuUI->SetChooseBarOutColor(sf::Color::Yellow);
	menuUI->SetChooseBarThickness(5.f);
	menuUI->SetChooseBarSize({ 700.f, 130.f });
	menuUI->SetChoosedColor(sf::Color::Yellow);
	menuUI->SetNotChoosedColor(sf::Color::White);
	menuUI->SetChooseBarOffset(sf::Vector2f{ 0.f, 15.f });

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
		menuUI->SetBarPos((menuUI->GetBarPos() + 1) % menuUI->GetMenuCount());
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && !menuUI->GetBarPos())
	{
		//SCENE_MGR.ChangeScene(SceneIds::Player1Mode);
		SCENE_MGR.setScene(SceneIds::Player2Mode);
		SCENE_MGR.ChangeScene(SceneIds::DuoCharacterChoose, true, SceneIds::Player2Mode);
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && menuUI->GetBarPos())
	{
		//SCENE_MGR.ChangeScene(SceneIds::Player2Mode);
		SCENE_MGR.setScene(SceneIds::ChallangeMode);
		SCENE_MGR.ChangeScene(SceneIds::DuoCharacterChoose, true, SceneIds::ChallangeMode);
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::BackSpace))
	{
		//SCENE_MGR.ChangeScene(SceneIds::Player2Mode);
		SCENE_MGR.ChangeScene(SceneIds::GameMode);
	}
}