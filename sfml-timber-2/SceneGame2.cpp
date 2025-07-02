#include "stdafx.h"
#include "SceneGame2.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"
#include "UiHud.h"
#include "MenuUI.h"

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
    texIds.push_back("graphics/player2.png");
    texIds.push_back("graphics/player3.png");
    texIds.push_back("graphics/player4.png");
    texIds.push_back("graphics/axe.png");
    texIds.push_back("graphics/rip.png");
    texIds.push_back("graphics/log.png");

    fontIds.push_back("fonts/Galmuri11-Bold.ttf");
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

    uiHud->SetLineActive(true);
    uiHud->SetType(UiHud::ModeType::player21);

    uiHud2 = (UiHud*)AddGameObject(new UiHud());
    uiHud2->SetType(UiHud::ModeType::player22);


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
    //player2->SetTexIds(SCENE_MGR.getDuoTexId());

    score = 0;
    score2 = 0;
    uiHud->SetScore(score);
    uiHud2->SetScore(score2);

    timer = timerMax;
    uiHud->SetTimeBar(timer / timerMax);
    uiHud2->SetTimeBar(timer / timerMax);

    uiHud->SetShowMassage(true);
    uiHud->SetMessage("Enter to Start!");

    menuUI->SetActive(false);
    menuUI2->SetActive(false);

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
        if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
        {
            isPlaying = false;
            menuUI2->SetActive(true);
            FRAMEWORK.SetTimeScale(0.f);
        }

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

                menuUI->SetActive(true);
                menuUI->SetActive(true);
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
                menuUI->SetActive(true);
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

            menuUI->SetActive(true);
            /*uiHud->SetShowMassage(true);
            uiHud->SetMessage("Enter to Restart!");*/
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
                menuUI->SetActive(false);
                uiHud2->SetShowMassage(false);
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

