#include "SpaceGame.h"
#include "Framework/Scene.h"
#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "Renderer/Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "GameData.h"

#include <vector>

using namespace viper;

bool SpaceGame::Initialize()
{
    m_scene = std::make_unique<Scene>(this);

	m_titleFont = std::make_shared<Font>();
	m_titleFont->Load("CactusSandwich.ttf", 50);

	m_uiFont = std::make_shared<Font>();
	m_uiFont->Load("CactusSandwich.ttf", 30);

	m_tittleText = std::make_unique<Text>(m_titleFont);
	m_scoreText = std::make_unique<Text>(m_uiFont);
	m_Text = std::make_unique<Text>(m_uiFont);

    return true;
}

void SpaceGame::Update(float dt)
{
    switch (m_gameState)
    {
    case SpaceGame::GameState::Initialize:
        m_gameState = GameState::StartGame;
        break;

    case SpaceGame::GameState::Title:
        if (viper::getEngine().getInput().getKeyPressed(SDL_SCANCODE_SPACE)) {
            m_gameState = GameState::StartGame;
        }
        break;

    case SpaceGame::GameState::StartGame:
        m_score = 0;
        m_lives = 3;
        m_gameState = GameState::StartRound;
        break;

    case SpaceGame::GameState::StartRound:
    {
        // create player
        std::shared_ptr<viper::Model> model = std::make_shared<viper::Model>(GameData::playerPoints, viper::vec3{ 0.0f, 0.4f, 1.0f });
        viper::Transform transform{ viper::vec2{ viper::getEngine().getRenderer().GetWidth() * 0.5f, viper::getEngine().getRenderer().GetHeight() * 0.5f }, 0, 5 };
        auto player = std::make_unique<Player>(transform, model);
        player->speed = 1500.0f;
        player->rotationRate = 180.0f;
        player->damping = 1.5f;
        player->name = "player";
        player->tag = "player";

        m_scene->AddActor(std::move(player));
        m_gameState = GameState::Game;
    }
    break;
    case SpaceGame::GameState::Game:
        enemySpawnTimer -= dt;
        if (enemySpawnTimer <= 0) {
            enemySpawnTimer = 4;

            // create enemies
            std::shared_ptr<viper::Model> enemyModel = std::make_shared<viper::Model>(GameData::enemyPoints, viper::vec3{ viper::random::getReal(), viper::random::getReal(), viper::random::getReal() });
            viper::Transform transform{ viper::vec2{ viper::random::getReal() * viper::getEngine().getRenderer().GetWidth(), viper::random::getReal() * viper::getEngine().getRenderer().GetHeight() }, 0, 10 };
            std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
            enemy->damping = 0.2f;
            enemy->speed = (viper::random::getReal() * 800) + 500;
            enemy->tag = "enemy";
            m_scene->AddActor(std::move(enemy));
        }

        break;
    case SpaceGame::GameState::PlayerDead:
        m_lives--;
        if (m_lives == 0) m_gameState = GameState::GameOver;
        else {
            m_gameState = GameState::StartRound;
        }
        break;
    case SpaceGame::GameState::GameOver:
        break;
    default:
        break;
    }

    m_scene->Update(viper::getEngine().getTime().GetDeltaTime());
}

void SpaceGame::Draw(viper::Renderer& renderer)
{
    m_scene->Draw(renderer);
}

void SpaceGame::Shutdown()
{
    //
}
