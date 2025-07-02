#include "stdafx.h"
#include "SceneGMChoose.h"
#include "SpriteGo.h"
#include "Tree.h"
#include "Player.h"
#include "MenuUI.h"

SceneGMChoose::SceneGMChoose()
	:Scene(SceneIds::GameMode)
{
}

SceneGMChoose::~SceneGMChoose()
{
}

void SceneGMChoose::Init()
{
	texIds.push_back("graphics/mainbackground.png");
	texIds.push_back("graphics/solomode.png");
	texIds.push_back("graphics/duomode.png");

	fontIds.push_back("fonts/Galmuri11-Bold.ttf");

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	AddGameObject(new SpriteGo("graphics/mainbackground.png"));

	solo = (SpriteGo*)AddGameObject(new SpriteGo("graphics/solomode.png"));
	solo->SetOrigin(Origins::MC);
	duo = (SpriteGo*)AddGameObject(new SpriteGo("graphics/duomode.png"));
	duo->SetOrigin(Origins::MC);

	menuUI = (MenuUI*)AddGameObject(new MenuUI());

	menuUI->SetFontId("fonts/Galmuri11-Bold.ttf");

	menuUI->AddMessages("1 Player");
	menuUI->AddMessages("2 Player");

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
	menuUI->SetChooseBarSize({ 500.f, 130.f });
	menuUI->SetChoosedColor(sf::Color::Yellow);
	menuUI->SetNotChoosedColor(sf::Color::White);
	menuUI->SetChooseBarOffset(sf::Vector2f{ 0.f, 15.f });

	Scene::Init();
}

void SceneGMChoose::Enter()
{
	Scene::Enter();

	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();

	solo->SetScale({ 0.4f,0.4f });
	solo->SetPosition({ bound.width / 2.f - 450.f, 400.f });

	duo->SetScale({ 0.4f,0.4f });
	duo->SetPosition({ bound.width / 2.f + 450.f, 400.f });
}

void SceneGMChoose::Exit()
{
	Scene::Exit();
}

void SceneGMChoose::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Left) || InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		menuUI->SetBarPos((menuUI->GetBarPos() + 1) % menuUI->GetMenuCount());
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && !menuUI->GetBarPos())
	{
		//SCENE_MGR.ChangeScene(SceneIds::Player1Mode);
		SCENE_MGR.ChangeScene(SceneIds::SoloCharacterChoose);
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && menuUI->GetBarPos())
	{
		//SCENE_MGR.ChangeScene(SceneIds::Player2Mode);
		SCENE_MGR.ChangeScene(SceneIds::DuoMode);
	}
}
