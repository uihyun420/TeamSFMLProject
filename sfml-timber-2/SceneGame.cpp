#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"
#include "UiHud.h"
#include "GameOverUI.h"
#include "CharacterSelectScene.h"
#include "DuoCharacterSelectScene.h"

#include "MenuUI.h"

SceneGame::SceneGame()
	: Scene(SceneIds::Player1Mode)
{
}

SceneGame::~SceneGame()
{
}


void SceneGame::Init()
{

    texIds.push_back("graphics/background1.png");
    texIds.push_back("graphics/cloud.png");
    texIds.push_back("graphics/bee.png");
    texIds.push_back("graphics/tree.png");
    texIds.push_back("graphics/branch.png");
    texIds.push_back("graphics/player.png");
    texIds.push_back("graphics/player2.png");
    texIds.push_back("graphics/axe.png");
    texIds.push_back("graphics/rip.png");
    texIds.push_back("graphics/log.png");

    fontIds.push_back("fonts/Galmuri11-Bold.ttf");

    //

    AddGameObject(new SpriteGo("graphics/background1.png"));
    
    for (int i = 0; i < 3; ++i)
    {
        BackgroundElement* element = (BackgroundElement*)AddGameObject(
            new BackgroundElement("graphics/cloud.png"));
    }

    tree = (Tree*)AddGameObject(new Tree());

    BackgroundElement* element = (BackgroundElement*)AddGameObject(
        new BackgroundElement("graphics/bee.png"));
    element->minScale = 1.f;
    element->maxScale = 1.f;
    element->minY = 600;
    element->maxY = 800;
    element->minSpeed = 400;
    element->maxSpeed = 600;
    element->SetMoveType(BackgroundElement::MoveType::Wave);

    player = (Player*)AddGameObject(new Player());

    uiHud = (UiHud*)AddGameObject(new UiHud());

    menuUI = (MenuUI*)AddGameObject(new MenuUI());

    menuUI->SetFontId("fonts/Galmuri11-Bold.ttf");

    sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
    menuUI->AddTextPos({ bounds.width * 0.5f, 350 });
    menuUI->AddTextPos({ bounds.width * 0.5f, 550 });
    menuUI->AddTextPos({ bounds.width * 0.5f, 750 });

    menuUI->AddMessages("Go to main!");
    menuUI->AddMessages("Game Restart!");
    menuUI->AddMessages("Exit Game");

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
    menuUI->SetChooseBarSize({ 800.f, 130.f });
    menuUI->SetChoosedColor(sf::Color::Yellow);
    menuUI->SetNotChoosedColor(sf::Color::White);
    menuUI->SetChooseBarPos(1);

    Scene::Init();
}

void SceneGame::Enter()
{
    Scene::Enter();




 
    sf::Vector2f pos = tree->GetPosition();
    pos.y = 950.f;
    player->SetPosition(pos);

    score = 0;
    uiHud->SetScore(score);

    timer = timerMax;
    uiHud->SetTimeBar(timer / timerMax);

    uiHud->SetShowMassage(true);
    uiHud->SetMessage("Enter to Start!");

    menuUI->SetActive(false);

    isPlaying = false;
}

void SceneGame::Exit()
{
    Scene::Exit();
}

void SceneGame::CreateLog(Player* p)
{
    BackgroundElement* log = (BackgroundElement*)AddGameObject(
        new BackgroundElement("graphics/log.png"));
    log->Reset();

    log->SetActive(true);
    //log->SetStartPos({ tree->GetSprite().getPosition().x, tree->GetSprite().getGlobalBounds().height });
    sf::Vector2f startPos = p->GetSprite().getPosition();
    startPos.y = tree->GetSprite().getGlobalBounds().height;
    log->SetStartPos(startPos);
    log->SetMoveType(BackgroundElement::MoveType::Fly);

    sf::Vector2f dir((rand() % 2 == 0) ? -1.f : 1.f, -1.f);
    log->vel = dir * log->logSpeed;
    log->isFlying = true;

    Logs.push_back(log);
}

void SceneGame::Update(float dt)
{
    Scene::Update(dt);

    if (isPlaying)
    {
        
        if (InputMgr::GetKeyDown(sf::Keyboard::Left))
        {
            tree->UpdateBranches();
            player->SetSide(Sides::Left);
            if (tree->GetSide() == player->GetSide())
            {
               FRAMEWORK.SetTimeScale(0.f);
                player->SetAlive(false);

                menuUI->SetActive(true);
                /*uiHud->SetShowMassage(true);
                uiHud->SetMessage("Enter to Restart!");*/
                isPlaying = false;
            }
            else
            {
                score += 10;
                uiHud->SetScore(score);
            }
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Right))
        {
            tree->UpdateBranches();
            player->SetSide(Sides::Right);
            if (tree->GetSide() == player->GetSide())
            {
                isPlaying = false;
                FRAMEWORK.SetTimeScale(0.f);
                player->SetAlive(false);
                menuUI->SetActive(true);
                /*uiHud->SetShowMassage(true);
                uiHud->SetMessage("Enter to Restart!");*/
            }
            else
            {
                score += 10;
                uiHud->SetScore(score);
            }
        }

        player->SetDrawAxe(
            InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right));
     
        if (!isPlaying) {
            player->SetDrawAxe(false);
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Right) || InputMgr::GetKeyDown(sf::Keyboard::Left)) {
            CreateLog(player);
        }

     
        timer -= dt;
        if (timer <= 0.f)
        {
            timer = 0.f;

            isPlaying = false;
            FRAMEWORK.SetTimeScale(0.f);
            player->SetAlive(false);

            menuUI->SetActive(true);
            /*uiHud->SetShowMassage(true);
            uiHud->SetMessage("Enter to Restart!");*/
        }
        uiHud->SetTimeBar(timer / timerMax);
    }
    else
    {
        if (!player->GetAlive())
        {
            for (auto log : Logs)
            {
                log->SetActive(false);
            }
        }
        if (InputMgr::GetKeyDown(sf::Keyboard::Down))
        {
            menuUI->SetBarPos((menuUI->GetBarPos() + 1) % menuUI->GetMenuCount());
        }
        else if (InputMgr::GetKeyDown(sf::Keyboard::Up))
        {
            menuUI->SetBarPos((menuUI->GetBarPos() + 2) % menuUI->GetMenuCount());
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && menuUI->GetBarPos() == (int)Menu::home)
        {
            SCENE_MGR.ChangeScene(SceneIds::GameStart);
        }
        else if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && menuUI->GetBarPos() == (int)Menu::exit)
        {
            FRAMEWORK.GetWindow().close();
        }
        else if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
        {
            FRAMEWORK.SetTimeScale(1.f);
            player->Reset();
            tree->Reset();
            isPlaying = true;

            score = 0;
            uiHud->SetScore(score);

            timer = timerMax;
            uiHud->SetTimeBar(timer / timerMax);

            uiHud->SetShowMassage(false);
            menuUI->SetActive(false);
        }
        
    }

    
}

