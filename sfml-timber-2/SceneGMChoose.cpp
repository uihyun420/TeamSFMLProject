#include "stdafx.h"
#include "SceneGMChoose.h"
#include "SpriteGo.h"
#include "Tree.h"
#include "Player.h"
#include "GameModeUI.h"

SceneGMChoose::SceneGMChoose()
	:Scene(SceneIds::GameMode)
{
}

SceneGMChoose::~SceneGMChoose()
{
}

void SceneGMChoose::Init()
{
	texIds.push_back("graphics/background.png");
	texIds.push_back("graphics/player.png");
	texIds.push_back("graphics/tree.png");

	fontIds.push_back("fonts/KOMIKAP_.ttf");

	AddGameObject(new SpriteGo("graphics/background.png"));

	for (int i = 0; i < 3; i++)
	{
		tree[i] = (Tree*)AddGameObject(new Tree());
	}

	player = (Player*)AddGameObject(new Player());

	gameModeUI = (GameModeUI*)AddGameObject(new GameModeUI());

	Scene::Init();
}

void SceneGMChoose::Enter()
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

void SceneGMChoose::Exit()
{
	Scene::Exit();
}

void SceneGMChoose::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Left) || InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		gameModeUI->SetBarPos((gameModeUI->GetBarPos() + 1) % gameModeUI->GetMenuCount());
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && !gameModeUI->GetBarPos())
	{
		//SCENE_MGR.ChangeScene(SceneIds::Player1Mode);
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && gameModeUI->GetBarPos())
	{
		//SCENE_MGR.ChangeScene(SceneIds::Player2Mode);
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}
}
