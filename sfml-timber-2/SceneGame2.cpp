#include "stdafx.h"
#include "SceneGame2.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"
#include "UiHud.h"
#include "GameOverUI.h"

SceneGame2::SceneGame2()
    : Scene(SceneIds::Player2Mode)
{
}

SceneGame2::~SceneGame2()
{
}


void SceneGame2::Init()
{
   
    texIds.push_back("graphics/background1.png");
    texIds.push_back("graphics/cloud.png");
    texIds.push_back("graphics/bee.png");
    texIds.push_back("graphics/tree.png");
    texIds.push_back("graphics/branch.png");
    texIds.push_back("graphics/player.png");
    texIds.push_back("graphics/axe.png");
    texIds.push_back("graphics/rip.png");
    texIds.push_back("graphics/log.png");

    fontIds.push_back("fonts/Galmuri11-Bold.ttf");


    AddGameObject(new SpriteGo("graphics/background1.png"));

    for (int i = 0; i < 3; ++i)
    {
        BackgroundElement* element = (BackgroundElement*)AddGameObject(
            new BackgroundElement("graphics/cloud.png"));
    }

    tree = (Tree*)AddGameObject(new Tree());
    tree2 = (Tree*)AddGameObject(new Tree());



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
    player2 = (Player*)AddGameObject(new Player("Player2"));

    uiHud = (UiHud*)AddGameObject(new UiHud());
    uiHud->SetLineActive(true);
    uiHud->SetType(UiHud::ModeType::player21);

    
    uiHud2 = (UiHud*)AddGameObject(new UiHud());
    uiHud2->SetType(UiHud::ModeType::player22);

    overUI = (GameOverUI*)AddGameObject(new GameOverUI());


    Scene::Init();

}

void SceneGame2::Enter()
{
    Scene::Enter();

    int w = FRAMEWORK.GetWindowSize().x / 2;
    tree->SetTwoPlayMode(true);
    tree->SetPosition({ w / 2.f , 0.f });

    tree2->SetTwoPlayMode(true);
    tree2->SetPosition({ w + (w / 2.f), 0.f });

    sf::Vector2f pos = tree->GetPosition();
    pos.y = 950.f;
    player->SetPosition(pos);

    sf::Vector2f pos2 = tree2->GetPosition();
    pos2.y = 950.f;
    player2->SetPosition(pos2);


    score = 0;
    score2 = 0;
    uiHud->SetScore(score);
    uiHud2->SetScore(score2);

    timer = timerMax;
    uiHud->SetTimeBar(timer / timerMax);
    uiHud2->SetTimeBar(timer / timerMax);

    uiHud->SetShowMassage(true);
    uiHud->SetMessage("Enter to Start!");

    overUI->SetActive(false);

    isPlaying = false;
}

void SceneGame2::Exit()
{
    Scene::Exit();
}

void SceneGame2::CreateLog(Player* p)
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

void SceneGame2::Update(float dt)
{
    Scene::Update(dt);

    if (isPlaying)
    {

        /*bgTime += dt;
        if (bgTime > 0.3f) {
            tree->UpdateBranches();
            bgTime = 0;
        }*/
        if (InputMgr::GetKeyDown(sf::Keyboard::A)) {
            tree2->UpdateBranches();
            player2->SetSide(Sides::Left);
            if (tree2->GetSide() == player2->GetSide())
            {
                FRAMEWORK.SetTimeScale(0.f);
                player2->SetAlive(false);

                overUI->SetActive(true);
                /*uiHud->SetShowMassage(true);
                uiHud->SetMessage("Enter to Restart!");*/
                isPlaying = false;
            }
            else
            {
                score2 += 10;
                uiHud2->SetScore(score2);
            }
        }
        else if (InputMgr::GetKeyDown(sf::Keyboard::D)) {
            tree2->UpdateBranches();
            player2->SetSide(Sides::Right);
            if (tree2->GetSide() == player2->GetSide())
            {
                isPlaying = false;
                FRAMEWORK.SetTimeScale(0.f);
                player2->SetAlive(false);
                overUI->SetActive(true);
                /*uiHud->SetShowMassage(true);
                uiHud->SetMessage("Enter to Restart!");*/
            }
            else
            {
                score2 += 10;
                uiHud2->SetScore(score2);
            }
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Left))
        {
            tree->UpdateBranches();
            player->SetSide(Sides::Left);
            if (tree->GetSide() == player->GetSide())
            {
                FRAMEWORK.SetTimeScale(0.f);
                player->SetAlive(false);

                overUI->SetActive(true);
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
                overUI->SetActive(true);
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
        player2->SetDrawAxe(
            InputMgr::GetKey(sf::Keyboard::A) || InputMgr::GetKey(sf::Keyboard::D));

        if (!isPlaying) {
            player->SetDrawAxe(false);
            player2->SetDrawAxe(false);
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Right) || InputMgr::GetKeyDown(sf::Keyboard::Left)) {
            CreateLog(player);
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::A) || InputMgr::GetKeyDown(sf::Keyboard::D)) {
            CreateLog(player2);
        }



        timer -= dt;

        if (timer <= 0.f)
        {
            timer = 0.f;

            isPlaying = false;
            FRAMEWORK.SetTimeScale(0.f);
            player->SetAlive(false);
            player2->SetAlive(false);

            overUI->SetActive(true);
        }
        uiHud->SetTimeBar(timer / timerMax);
        uiHud2->SetTimeBar(timer / timerMax);
    }
    else
    {
        if (!player->GetAlive() || !player2->GetAlive())
        {
            for (auto log : Logs)
            {
                log->SetActive(false);
            }
        }
        if (InputMgr::GetKeyDown(sf::Keyboard::Down))
        {
            overUI->SetBarPos((overUI->GetBarPos() + 1) % overUI->GetMenuCount());
        }
        else if (InputMgr::GetKeyDown(sf::Keyboard::Up))
        {
            overUI->SetBarPos((overUI->GetBarPos() + 2) % overUI->GetMenuCount());
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && overUI->GetBarPos() == (int)Menu::home)
        {
            SCENE_MGR.ChangeScene(SceneIds::GameStart);
        }
        else if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && overUI->GetBarPos() == (int)Menu::exit)
        {
            FRAMEWORK.GetWindow().close();
        }
        if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
        {
            FRAMEWORK.SetTimeScale(1.f);
            player->Reset();
            player2->Reset();
            tree->Reset();
            tree2->Reset();
            isPlaying = true;

            score = 0;
            score2 = 0;
            uiHud->SetScore(score);
            uiHud2->SetScore(score2);

            timer = timerMax;
            uiHud->SetTimeBar(timer / timerMax);
            uiHud2->SetTimeBar(timer / timerMax);

            uiHud->SetShowMassage(false);
            uiHud2->SetShowMassage(false);
            overUI->SetActive(false);
        }
    }


}

