#include "../Wizard/Math/Math.h"
#include "../Wizard/Math/Vector2.h"
#include "../Wizard/Core/Random.h"
#include "../Wizard/Core/Time.h"
#include "../Wizard/Renderer/Renderer.h"
#include "../Wizard/Input/InputSystem.h"


#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>  
#include <fmod.hpp>

int main(int argc, char* argv[]) {
    viper::Time time;
    Renderer renderer;
    
    renderer.Inatialize();
    renderer.CreateWindow("Viper Engine", 1280, 1024);

    viper::InputSystem input;
    input.Inatialize();

    SDL_Event e;
    bool quit = false;

    //create start
    std::vector<viper::vec2> starts;
    for (int i = 0;i < 100;i++)
    {
        starts.push_back(viper::vec2{viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1024});
    }

    std::vector<viper::vec2> points;

    // create audio system
    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

    FMOD::Sound* sound = nullptr;
    audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

    audio->playSound(sound, 0, false, nullptr);

    //MAIN LOOP
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        input.Update();
        if (input.getKeyPressed(SDL_SCANCODE_A)) {
            std::cout << "Pressed \n";
        }

        if (input.GetMouseButtonDown(viper::InputSystem::mouseButton::Left)) {
            std::cout << "mouse pressed \n";
        }
        //audio
        audio->update();

        viper::vec2 mouse = input.GetMousePosition();
        //cout << mouse.x << " " << mouse.y << endl;

        renderer.SetColor(0, 0, 0);
        renderer.Clear();


        if (input.GetMouseButtonDown(viper::InputSystem::mouseButton::Left)) {
            viper::vec2 position = input.GetMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Lenght() > 10) points.push_back(position);
        }


        for (int i = 0; i < (int)points.size() - 1; i++) {
            renderer.SetColor(viper::random::getRandomInt(256), viper::random::getRandomInt(256), viper::random::getRandomInt(256));
            renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        viper::vec2 speed{ -140.0f,0.0f };
        float length = speed.Lenght();

        for (auto& star : starts) {
            star += speed * time.GetDeltaTime();
            //star = star.Add(speed);

            if (star[0] > 1280) star[0] = 0;
            if (star[0] < 0) star[0] = 1280;
            renderer.SetColor(viper::random::getRandomInt(256), viper::random::getRandomInt(256), viper::random::getRandomInt(256));
            renderer.DrawPoint(star.x, star.y);
        }


        renderer.Present();
    }

    renderer.ShutDown();

    return 0;
}
