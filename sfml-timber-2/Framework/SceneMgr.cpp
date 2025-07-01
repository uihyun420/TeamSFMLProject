#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneGame.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
#include "SceneStart.h"
#include "SceneGMChoose.h"

void SceneMgr::Init()
{
	scenes.push_back(new SceneGame());
	scenes.push_back(new SceneStart());
	scenes.push_back(new SceneGMChoose());
	//scenes.push_back(new SceneSingleMode());
	scenes.push_back(new SceneDev1());
	//scenes.push_back(new SceneDuoMode());
	scenes.push_back(new SceneDev2());
	//scenes.push_back(new SceneCharacterChoose());
	scenes.push_back(new SceneDev1());
	scenes.push_back(new SceneDev1());
	scenes.push_back(new SceneDev2());

	for (auto scene : scenes)
	{
		scene->Init();
	}

	currentScene = startScene;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : scenes)
	{
		if (scene->Id == currentScene)
		{
			scene->Exit();
		}
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	nextScene = id;
}

void SceneMgr::Update(float dt)
{
	if (nextScene != SceneIds::None)
	{
		scenes[(int)currentScene]->Exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		scenes[(int)currentScene]->Enter();
	}

	scenes[(int)currentScene]->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->Draw(window);
}
