#include "../Wizard/Math/Math.h"
#include "../Wizard/Math/Vector2.h"
#include "../Wizard/Math/Vector3.h"
#include "../Wizard/Core/Random.h"
#include "../Wizard/Core/Time.h"
#include "../Wizard/Renderer/Renderer.h"
#include "../Wizard/Input/InputSystem.h"
#include "../Wizard/AudioSystem.h"
#include "../Wizard/Renderer/Model.h"
#include "../Wizard/Math/Transform.h"

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

    std::vector<viper::vec2> starts;
    for (int i = 0; i < 100; i++) {
        starts.push_back(viper::vec2{
            viper::random::getRandomFloat() * 1280,
            viper::random::getRandomFloat() * 1024
            });
    }

    
    std::vector<viper::vec2> airplanePoints = {
        {0, 0},       
        {60, 20},     
        {50, 15},     
        {40, 10},     
        {40, 5},      
        {20, 5},      
        {20, -5},    
        {40, -5},     
        {40, -10},    
        {50, -15},    
        {60, -20},    
        {0, 0}        
    };

    viper::vec3 airplaneColor = { 0.0f, 0.7f, 1.0f }; 

    viper::Model airplaneModel(airplanePoints, airplaneColor);

    viper::Transform transform;
    transform.position = { 640, 512 };  
    transform.rotation = 0.0f;
    transform.scale = 1.0f;

    std::vector<viper::vec2> points; 

    viper::AudioSystem audio;
    audio.Iniatialize();
    audio.AddSound("bass.wav", "bass");
    audio.AddSound("snare.wav", "snare");
    audio.AddSound("open-hat.wav", "open-hat");

    while (!quit) {
        time.Tick();

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        audio.Update();
        input.Update();

        if (input.getKeyPressed(SDL_SCANCODE_Q)) audio.PlaySound("bass");
        if (input.getKeyPressed(SDL_SCANCODE_W)) audio.PlaySound("snare");
        if (input.getKeyPressed(SDL_SCANCODE_E)) audio.PlaySound("open-hat");

        
        viper::vec2 speed{ -140.0f, 0.0f };
        for (auto& star : starts) {
            star += speed * time.GetDeltaTime();
            if (star[0] > 1280) star[0] = 0;
            if (star[0] < 0) star[0] = 1280;
        }

        
        renderer.SetColor(0.0f, 0.0f, 0.0f);
        renderer.Clear();

      

        
        airplaneModel.Draw(renderer, transform);

       
        if (input.GetMouseButtonDown(viper::InputSystem::mouseButton::Left)) {
            viper::vec2 pos = input.GetMousePosition();
            if (points.empty() || (pos - points.back()).Lenght() > 10) {
                points.push_back(pos);
            }
        }

        renderer.Present();
    }

    renderer.ShutDown();
    audio.Shutdown();

    return 0;
}
