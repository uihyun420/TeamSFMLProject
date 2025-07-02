#include "stdafx.h"
#include "SceneStart.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "GameStartUI.h"

SceneStart::SceneStart()
	: Scene(SceneIds::GameStart)
{
}

SceneStart::~SceneStart()
{
}

void SceneStart::Init()
{
	texIds.push_back("graphics/mainbackground.png");

	fontIds.push_back("fonts/Galmuri11-Bold.ttf");

	AddGameObject(new SpriteGo("graphics/mainbackground.png"));

	TextGo* go = new TextGo("fonts/Galmuri11-Bold.ttf");
	go->SetString("Timber Game!");
	go->SetCharacterSize(150);
	go->SetFillColor(sf::Color::White);
	go->SetOrigin(Origins::MC);
	go->SetPosition({ FRAMEWORK.GetWindowBounds().width / 2.f, FRAMEWORK.GetWindowBounds().height / 2.f - 300.f });
	AddGameObject(go);

	startUI = (GameStartUI*)AddGameObject(new GameStartUI());

	Scene::Init();
}

void SceneStart::Enter()
{
	Scene::Enter();

	/*player->SetPosition({ 100.f, 1000.f });
	player->SetScale({ -5.f, 5.f });
	sf::Vector2f treePos = tree[0]->GetPosition();
	sf::Vector2f offset = { 150.f,0.f };
	for (int i = 0; i < 3; i++)
	{
		tree[i]->SetPosition(treePos);
		treePos.x += 350.f;
	}*/
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
		startUI->SetBarPos((startUI->GetBarPos() + 1) % startUI->GetMenuCount());
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && !startUI->GetBarPos())
	{
		SCENE_MGR.ChangeScene(SceneIds::GameMode);
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && startUI->GetBarPos())
	{
		FRAMEWORK.GetWindow().close();
	}
}
