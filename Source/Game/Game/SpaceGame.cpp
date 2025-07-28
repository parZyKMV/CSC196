//#include "SpaceGame.h"
//#include "../Wizard/Renderer/Engine.h"
//#include "../Wizard/Renderer/Renderer.h"
//#include "../Wizard/Renderer/Model.h"
//#include "../Wizard/FrameWork/Scene.h"
//#include "../Wizard/Core/Random.h"
//#include "../Wizard/Math/Vector2.h"
//#include "Enemy.h"
//#include "Player.h"
//
//#include <vector>
//
//using namespace viper;
//
//bool SpaceGame::Initialize() {
//	scene = std::make_unique<Scene>();
//
//    std::vector<vec2> airplanePoints = {
//        {0, 0},
//        {60, 20},
//        {50, 15},
//        {40, 10},
//        {40, 5},
//        {20, 5},
//        {20, -5},
//        {40, -5},
//        {40, -10},
//        {50, -15},
//        {60, -20},
//        {0, 0}
//    };
//
//    std::shared_ptr<Model> airplane_model = std::make_shared<Model>(airplanePoints, viper::vec3{ 96, 255, 41 });
//
//    Transform transform{vec2{getEngine().getRenderer().GetWidth() * 0.5f , viper::getEngine().getRenderer().GetHeight() * 0.5f}, 0, 2 };
//    std::unique_ptr<Player> player = std::make_unique<Player>(transform, airplane_model);
//
//    player->speed = 500.0f;
//    player->rotationRate = 180.0f;
//    player->damping = 0.5f;
//    player->name = "player";
//
//    scene->AddActor(std::move(player));
//
//    std::shared_ptr<viper::Model> enemy_model = std::make_shared<viper::Model>(airplanePoints, viper::vec3{255, 46, 46});
//
//
//    //create enemies
//    for (int i = 0; i < 10; i++) {
//        viper::Transform enemy_transform{ viper::vec2{ random::getReal() * getEngine().getRenderer().GetWidth(), random::getReal() * getEngine().getRenderer().GetHeight() }, 0, 2 };
//        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(enemy_transform, enemy_model);
//        enemy->speed = random::getReal() * 500;
//        enemy->damping = 1.5f;
//        scene->AddActor(std::move(enemy));
//    }
//
//    // SAVING CODE FOR ENEMY CODE
//    /*for (int i = 0; i < 10; i++) {
//        viper::Transform transform{ viper::vec2{viper::random::getReal() * 1280, viper::random::getReal() * 1024}, 0, 2 };
//        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
//        scene->AddActor(std::move(player));
//    }*/
//
//    // FONT CREATION
//    /*std::unique_ptr<viper::Font> font = std::make_unique<viper::Font>();
//    font->Load("ArcadeClassic.ttf", 20);*/
//
//    // TEXT CREATION
//    /*_text = std::make_unique<viper::Text>(font);
//    _text->Create(viper::GetEngine().GetRenderer(), "Hello World", viper::vec3{ 1, 1, 1 });*/
//
//    return true;
//}
//
//void SpaceGame::Update() {
//    scene->Update(viper::getEngine().getTime().GetDeltaTime());
//}
//
//void SpaceGame::Draw() {
//    scene->Draw(viper::getEngine().getRenderer());
//
//    //// DRAW TEXT
//    //_text->Draw(viper::GetEngine().GetRenderer(), 40.0f, 40.0f);
//}
//
//void SpaceGame::Shutdown() {
//
//}



