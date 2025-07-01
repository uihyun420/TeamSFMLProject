#include "stdafx.h"
#include "SceneStart.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Player.h"
#include "Tree.h"

SceneStart::SceneStart()
	: Scene(SceneIds::GameStart)
{
}

SceneStart::~SceneStart()
{
}

void SceneStart::Init()
{
	texIds.push_back("graphics/background.png");
	texIds.push_back("graphics/player.png");
	texIds.push_back("graphics/tree.png");
	texIds.push_back("graphics/axe.png");

	fontIds.push_back("fonts/KOMIKAP_.ttf");

	AddGameObject(new SpriteGo("graphics/background.png"));

	for (int i = 0; i < 3; i++)
	{
		tree[i] = (Tree*)AddGameObject(new Tree());
	}

	player = (Player*)AddGameObject(new Player());

	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetString("Timber Game!");
	go->SetCharacterSize(150);
	go->SetFillColor(sf::Color::White);
	go->SetOrigin(Origins::MC);
	go->SetPosition({ FRAMEWORK.GetWindowBounds().width / 2.f, FRAMEWORK.GetWindowBounds().height / 2.f - 300.f });
	AddGameObject(go);

	Scene::Init();
}

void SceneStart::Enter()
{
	Scene::Enter();

	player->SetPosition({ 100.f, 1000.f });
	player->SetScale({ -5.f, 5.f });
	sf::Vector2f treePos = tree[0]->GetPosition();
	sf::Vector2f offset = { 150.f,0.f };
	for (int i = 0; i < 3; i++)
	{
		tree[i]->SetPosition(treePos);
		treePos.x += 350.f;
	}
}

void SceneStart::Exit()
{
	Scene::Exit();
}

void SceneStart::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
}
