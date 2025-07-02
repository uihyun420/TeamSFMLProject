#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneGame.h"
#include "SceneGame2.h"
#include "SceneGame3.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
#include "SceneDev3.h"
#include "SceneStart.h"
#include "SceneGMChoose.h"
#include "SceneDuoChoose.h"
#include "CharacterSelectScene.h"
#include "DuoCharacterSelectScene.h"


void SceneMgr::Init()
{
	scenes.push_back(new SceneStart());
	scenes.push_back(new SceneGMChoose());
	scenes.push_back(new SceneDuoChoose());
	scenes.push_back(new SceneGame());
	//scenes.push_back(new SceneDuoMode());
	scenes.push_back(new SceneGame2());
	//scenes.push_back(new SceneChallangeMode());
	scenes.push_back(new SceneGame3());
	//scenes.push_back(new SceneSingleChoose());
	scenes.push_back(new CharacterSelectScene());
	scenes.push_back(new DuoCharacterSelectScene());
	

	//scenes.push_back(new SceneDuoChoose());
	scenes.push_back(new SceneDev2());
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

void SceneMgr::ChangeScene(SceneIds id, bool duo, SceneIds duomode)
{
	nextScene = id;
	isDuo = duo;
	if (isDuo)
	{
		this->duomode = duomode;
	}
}

void SceneMgr::setTexId(const std::string& s, bool solo , const std::string& duo)
{
	if (!solo)
	{
		texId = s;
	}
	else
	{
		texId = s;
		texId2 = duo;
		isDuo = true;
	}
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





