#include "stdafx.h"
#include "SceneGame2.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"
#include "UiHud.h"

SceneGame2::SceneGame2()
    : Scene(SceneIds::Player2Mode)
{
}

SceneGame2::~SceneGame2()
{
}


void SceneGame2::Init()
{
    texIds.push_back("graphics/background.png");
    texIds.push_back("graphics/cloud.png");
    texIds.push_back("graphics/bee.png");
    texIds.push_back("graphics/tree.png");
    texIds.push_back("graphics/branch.png");
    texIds.push_back("graphics/player.png");
    texIds.push_back("graphics/axe.png");
    texIds.push_back("graphics/rip.png");
    texIds.push_back("graphics/log.png");

    fontIds.push_back("fonts/KOMIKAP_.ttf");

    //

    AddGameObject(new SpriteGo("graphics/background.png"));

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
    player2 = (Player*)AddGameObject(new Player("Player2"));

    uiHud = (UiHud*)AddGameObject(new UiHud());

    Scene::Init();
}

void SceneGame2::Enter()
{
    Scene::Enter();

    sf::Vector2f pos = tree->GetPosition();
    pos.y = 950.f;
    player->SetPosition(pos);
    player2->SetPosition(pos);
    player2->SetSide(Sides::Left);


    score = 0;
    uiHud->SetScore(score);

    timer = timerMax;
    uiHud->SetTimeBar(timer / timerMax);

    uiHud->SetShowMassage(true);
    uiHud->SetMessage("Enter to Start!");
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
        bgTime += dt;
        if (bgTime > 0.3f) {
            tree->UpdateBranches();
            bgTime = 0;
        }
        if (InputMgr::GetKeyDown(sf::Keyboard::A)) {
            player2->SetSide(Sides::Left);
            //tree->UpdateBranches(); 
        }
        else if (InputMgr::GetKeyDown(sf::Keyboard::D)) {
            player2->SetSide(Sides::Right);
            //tree->UpdateBranches();
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Left))
        {
            player->SetSide(Sides::Left);
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Right))
        {
            player->SetSide(Sides::Right);
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

            uiHud->SetShowMassage(true);
            uiHud->SetMessage("Enter to Restart!");
        }
        uiHud->SetTimeBar(timer / timerMax);
    }
    else
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
        {
            FRAMEWORK.SetTimeScale(1.f);
            player->Reset();
            player2->Reset();
            //player2->SetSide(Sides::Left);
            tree->Reset();
            isPlaying = true;

            score = 0;
            uiHud->SetScore(score);

            timer = timerMax;
            uiHud->SetTimeBar(timer / timerMax);

            uiHud->SetShowMassage(false);
        }
    }


}

