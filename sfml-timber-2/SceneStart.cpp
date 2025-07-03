#include "stdafx.h"
#include "SceneStart.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "MenuUI.h"



SceneStart::SceneStart()
	: Scene(SceneIds::GameStart)
{
}

SceneStart::~SceneStart()
{
}

void SceneStart::Init()
{
	bgm.openFromFile("sound/BGM_01.wav");
	bgm.setLoop(true);
	bgm.setVolume(bgmVolume);
	bgm.play();
	

	texIds.push_back("graphics/mainbackground.png");

	fontIds.push_back("fonts/Galmuri11-Bold.ttf");

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	AddGameObject(new SpriteGo("graphics/mainbackground.png"));

	TextGo* go = new TextGo("fonts/Galmuri11-Bold.ttf");
	go->SetString("Timber Game!");
	go->SetCharacterSize(150);
	go->SetFillColor(sf::Color::White);
	go->SetOrigin(Origins::MC);
	go->SetPosition({ bounds.width / 2.f, bounds.height / 2.f - 300.f });
	AddGameObject(go);

	menuUI = (MenuUI*)AddGameObject(new MenuUI());

	menuUI->SetFontId("fonts/Galmuri11-Bold.ttf");

	menuUI->AddMessages("Game Start!"); 
	menuUI->AddMessages("Exit Game!");

	menuUI->AddTextPos({ bounds.width * 0.5f, 550 });
	menuUI->AddTextPos({ bounds.width * 0.5f, 750 });

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

	Scene::Init();
}

void SceneStart::Enter()
{
	Scene::Enter();
}

void SceneStart::Exit()
{
	Scene::Exit();
}

void SceneStart::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Down) || InputMgr::GetKeyDown(sf::Keyboard::Up))
	{
		menuUI->SetBarPos((menuUI->GetBarPos() + 1) % menuUI->GetMenuCount());
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && !menuUI->GetBarPos())
	{
		SCENE_MGR.ChangeScene(SceneIds::GameMode);
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && menuUI->GetBarPos())
	{
		FRAMEWORK.GetWindow().close();
	}



	if (InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		bgmVolume = std::max(0.f, bgmVolume - 10.f);
		bgm.setVolume(bgmVolume);
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	{
		bgmVolume = std::min(100.f, bgmVolume + 10.f);
		bgm.setVolume(bgmVolume);
	}



}
