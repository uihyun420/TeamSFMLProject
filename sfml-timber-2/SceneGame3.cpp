#include "stdafx.h"
#include "SceneGame3.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"
#include "UiHud.h"
#include "MenuUI.h"

SceneGame3::SceneGame3()
    : Scene(SceneIds::ChallangeMode)
{
}

SceneGame3::~SceneGame3()
{
}


void SceneGame3::Init()
{
    texIds.push_back("graphics/background1.png");
    texIds.push_back("graphics/cloud.png");
    texIds.push_back("graphics/bee.png");
    texIds.push_back("graphics/tree.png");
    texIds.push_back("graphics/branch.png");
    texIds.push_back("graphics/player.png");
    texIds.push_back("graphics/player2.png");
    texIds.push_back("graphics/player3.png");
    texIds.push_back("graphics/player4.png");
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

    beeElement = (BackgroundElement*)AddGameObject(
        new BackgroundElement("graphics/bee.png"));
    beeElement->minScale = 1.f;
    beeElement->maxScale = 1.f;
    beeElement->minY = 600;
    beeElement->maxY = 800;
    beeElement->minSpeed = 400;
    beeElement->maxSpeed = 600;
    beeElement->SetMoveType(BackgroundElement::MoveType::Wave);

    CrazyE = (BackgroundElement*)AddGameObject(
        new BackgroundElement("graphics/player.png"));
    CrazyE->minScale = 1.f;
    CrazyE->maxScale = 1.f;
    CrazyE->minY = 600;
    CrazyE->maxY = 800;
    CrazyE->minSpeed = 400;
    CrazyE->maxSpeed = 600;
    CrazyE->SetMoveType(BackgroundElement::MoveType::Crazy);

    player = (Player*)AddGameObject(new Player());
    player2 = (Player*)AddGameObject(new Player("Player2"));

    uiHud = (UiHud*)AddGameObject(new UiHud());
    uiHud2 = (UiHud*)AddGameObject(new UiHud());
    uiHud2->SetType(UiHud::ModeType::player22);

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

    menuUI2 = (MenuUI*)AddGameObject(new MenuUI());

    menuUI2->SetFontId("fonts/Galmuri11-Bold.ttf");

    menuUI2->AddTextPos({ bounds.width * 0.5f, 350 });
    menuUI2->AddTextPos({ bounds.width * 0.5f, 550 });
    menuUI2->AddTextPos({ bounds.width * 0.5f, 750 });

    menuUI2->AddMessages("Go to Home!");
    menuUI2->AddMessages("Game Restart!");
    menuUI2->AddMessages("Game Resume!");

    for (int i = 0; i < menuUI2->GetMenuCount(); i++)
    {
        TextGo text;
        text.SetCharacterSize(100);
        text.SetFillColor(sf::Color::White);
        text.SetPosition(menuUI2->GetTextPos()[i]);
        text.SetOrigin(Origins::MC);
        menuUI2->AddTextGo(text);
    }

    menuUI2->SetChooseBarColor(sf::Color(0, 0, 0, 0));
    menuUI2->SetChooseBarOutColor(sf::Color::Yellow);
    menuUI2->SetChooseBarThickness(5.f);
    menuUI2->SetChooseBarSize({ 800.f, 130.f });
    menuUI2->SetChoosedColor(sf::Color::Yellow);
    menuUI2->SetNotChoosedColor(sf::Color::White);
    menuUI2->SetChooseBarPos(1);

    Scene::Init();
}

void SceneGame3::Enter()
{
    Scene::Enter();

    sf::Vector2f pos = tree->GetPosition();
    pos.y = 950.f;
    player->SetPosition(pos);
    player2->SetPosition(pos);
    player2->SetSide(Sides::Left);

    score = 0;
    uiHud->SetScore(score);
    uiHud2->SetScore(score);

    timer = 0;
    uiHud->SetTimeBar(timer / timerMax);
    uiHud2->SetTimeBar(timer / timerMax);

    uiHud->SetShowMassage(true);
    uiHud2->SetShowMassage(true);
    uiHud->SetMessage("Enter to Start!");
    uiHud2->SetMessage("Enter to Start!");

    menuUI->SetActive(false);
    menuUI2->SetActive(false);
}

void SceneGame3::Exit()
{
    Scene::Exit();
}

void SceneGame3::CreateLog(Player* p)
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

void SceneGame3::Update(float dt)
{
    Scene::Update(dt);

    if (isPlaying)
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
        {
            isPlaying = false;
            menuUI2->SetActive(true);
            FRAMEWORK.SetTimeScale(0.f);
        }

        bgTime += dt;
        if (bgTime > 0.3f) {
            tree->UpdateBranches();
            bgTime = 0;
            score += 10;
            if (player->GetAlive())
            {
                uiHud->SetScore(score);
            }
            if (player2->GetAlive())
            {
                uiHud2->SetScore(score);
            }
        }

        sf::Vector2u playerSize = player->GetSprite().getTexture()->getSize();
        sf::Vector2f player1Pos = player->GetSprite().getPosition();
        sf::Vector2f player2Pos = player2->GetSprite().getPosition();

        if (InputMgr::GetKey(sf::Keyboard::A) && player2Pos.x >= playerSize.x / 2.f && player2->GetAlive()) {
            //player2->SetSide(Sides::Left);
            player2Pos += player2Speed * dt * sf::Vector2f({-1.f,0.f});
            player2->GetSprite().setPosition(player2Pos);
            player2->SetScale({ 1.f,1.f });
            //tree->UpdateBranches(); 
        }
        else if (InputMgr::GetKey(sf::Keyboard::D) && player2Pos.x <= 1920 - playerSize.x / 2.f && player2->GetAlive()) {
            //player2->SetSide(Sides::Right);
            player2Pos += player2Speed * dt * sf::Vector2f({ 1.f,0.f });
            player2->GetSprite().setPosition(player2Pos);
            player2->SetScale({ -1.f,1.f });
            //tree->UpdateBranches();
        }
        else if (InputMgr::GetKey(sf::Keyboard::W))
        {

        }

        if (InputMgr::GetKey(sf::Keyboard::Left) && player1Pos.x >= playerSize.x / 2.f && player->GetAlive())
        {
            //player->SetSide(Sides::Left);
            player1Pos += player1Speed * dt * sf::Vector2f({ -1.f,0.f });
            player->GetSprite().setPosition(player1Pos);
            player->SetScale({ 1.f,1.f });
        }

        if (InputMgr::GetKey(sf::Keyboard::Right) && player1Pos.x <= 1920 - playerSize.x / 2.f && player->GetAlive())
        {
            //player->SetSide(Sides::Right);
            player1Pos += player1Speed * dt * sf::Vector2f({ 1.f,0.f });
            player->GetSprite().setPosition(player1Pos);
            player->SetScale({ -1.f,1.f });
        }

        /*player->SetDrawAxe(
            InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right));
        player2->SetDrawAxe(
            InputMgr::GetKey(sf::Keyboard::A) || InputMgr::GetKey(sf::Keyboard::D));*/

        if (!isPlaying) {
            player->SetDrawAxe(false);
            player2->SetDrawAxe(false);
        }

        if ((InputMgr::GetKeyDown(sf::Keyboard::Right) || InputMgr::GetKeyDown(sf::Keyboard::Left)) && player->GetAlive()) {
            CreateLog(player);
        }

        if ((InputMgr::GetKeyDown(sf::Keyboard::A) || InputMgr::GetKeyDown(sf::Keyboard::D)) && player2->GetAlive()) {
            CreateLog(player2);
        }

        if (!Utils::getDistanceWithSize(player->GetSprite(), beeElement->GetSprite()))
        {
            player1Speed = 0.f;
            player->SetAlive(false);
        }
        if (!Utils::getDistanceWithSize(player2->GetSprite(), beeElement->GetSprite()))
        {
            player2Speed = 0.f;
            player2->SetAlive(false);
        }

        if (!Utils::getDistanceWithSize(player->GetSprite(), CrazyE->GetSprite()))
        {
            player1Speed = 0.f;
            player->SetAlive(false);
        }
        if (!Utils::getDistanceWithSize(player2->GetSprite(), CrazyE->GetSprite()))
        {
            player2Speed = 0.f;
            player2->SetAlive(false);
        }

        if (player1Speed == 0.f && player2Speed == 0.f)
        {
            isPlaying = false;
            FRAMEWORK.SetTimeScale(0.f);

            menuUI->SetActive(true);
        }
       
        //timer -= dt;
        //if (timer <= 0.f)
        //{
        //    timer = 0.f;

        //    isPlaying = false;
        //    FRAMEWORK.SetTimeScale(0.f);
        //    player->SetAlive(false);

        //    menuUI->SetActive(true);
        //    /*uiHud->SetShowMassage(true);
        //    uiHud->SetMessage("Enter to Restart!");*/
        //}
        //uiHud->SetTimeBar(timer / timerMax);
    }
    else
    {
        if (!player->GetAlive() && !player2->GetAlive())
        {
            for (auto log : Logs)
            {
                log->SetActive(false);
            }
        }
        if (!menuUI2->GetActive())
        {
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
                player->SetAlive(true);
                player2->Reset();
                player2->SetAlive(true);
                player1Speed = playerInitSpeed;
                player2Speed = playerInitSpeed;
                //player2->SetSide(Sides::Left);
                tree->Reset();
                beeElement->Reset();
                isPlaying = true;

                score = 0;
                uiHud->SetScore(score);
                uiHud2->SetScore(score);

                timer = 0;
                uiHud->SetTimeBar(timer / timerMax);

                uiHud->SetShowMassage(false);
                uiHud2->SetShowMassage(false);
                menuUI->SetActive(false);
            }
        }
        else
        {
            if (InputMgr::GetKeyDown(sf::Keyboard::Down))
            {
                menuUI2->SetBarPos((menuUI2->GetBarPos() + 1) % menuUI2->GetMenuCount());
            }
            else if (InputMgr::GetKeyDown(sf::Keyboard::Up))
            {
                menuUI2->SetBarPos((menuUI2->GetBarPos() + 2) % menuUI2->GetMenuCount());
            }

            if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && menuUI2->GetBarPos() == (int)Menu::restart)
            {
                for (auto log : Logs)
                {
                    log->SetActive(false);
                }
                FRAMEWORK.SetTimeScale(1.f);
                player->Reset();
                player->SetAlive(true);
                player2->Reset();
                player2->SetAlive(true);
                player1Speed = playerInitSpeed;
                player2Speed = playerInitSpeed;
                //player2->SetSide(Sides::Left);
                tree->Reset();
                beeElement->Reset();
                isPlaying = true;

                score = 0;
                uiHud->SetScore(score);
                uiHud2->SetScore(score);

                timer = 0;
                uiHud->SetTimeBar(timer / timerMax);

                uiHud->SetShowMassage(false);
                uiHud2->SetShowMassage(false);
                menuUI2->SetActive(false);
            }
            else if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && menuUI2->GetBarPos() == (int)Menu::home)
            {
                SCENE_MGR.ChangeScene(SceneIds::GameStart);
            }
            else if (InputMgr::GetKeyDown(sf::Keyboard::Enter) || InputMgr::GetKeyDown(sf::Keyboard::Escape))
            {
                FRAMEWORK.SetTimeScale(1.f);
                isPlaying = true;
                menuUI2->SetActive(false);
            }
        }
    }


}

