#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "AudioSystem.h"
#include "Renderer/Model.h"
#include "Math/Transform.h"
#include "../Wizard/Renderer/Engine.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>  
#include <fmod.hpp>
#include <memory>

using namespace viper;

int main(int argc, char* argv[]) {
    //viper::Time time;
    //viper::Renderer renderer;

    //renderer.Inatialize();
    //renderer.CreateWindow("Viper Engine", 1280, 1024);

    //viper::InputSystem input;
    //input.Inatialize();

    ////create audio system
    //viper::AudioSystem audio;
    //audio.Iniatialize();

    SDL_Event e;
    bool quit = false;

    //start all requiremts with Engine.h

    getEngine().Initialize();
    
    
    std::vector<vec2> airplanePoints = {
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

    vec3 airplaneColor = { 0.0f, 0.7f, 1.0f }; 
    Model airplaneModel(airplanePoints, airplaneColor);
    Transform transform{ vec2 {640,512},0,1 };

    std::vector<vec2> points; 

    // iniatilize sounds
    getEngine().getAudio().AddSound("bass.wav", "bass");
    getEngine().getAudio().AddSound("snare.wav", "snare");
    getEngine().getAudio().AddSound("open-hat.wav", "open-hat");

	// load the font
    Font* font = new Font();
    font->Load("CactusSandwich.ttf", 50);

	// create a text object
    Text* text = new Text(font);
    text->Create(getEngine().getRenderer(), "Hello World", vec3{1.0f, 1.0f, 1.0f});
     
    //create starts
    std::vector<vec2> starts;
    for (int i = 0; i < 100; i++) {
        starts.push_back(viper::vec2{
            viper::random::getReal() * 1280,
            viper::random::getReal() * 1024
            });
    }

    while (!quit) {
        getEngine().getTime().Tick();

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        if (getEngine().getInput().getKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        getEngine().getAudio().Update();
        getEngine().getInput().Update();


        /*if (getEngine().getInput().getKeyPressed(SDL_SCANCODE_Q)) getEngine().getAudio().PlaySound("bass");
        if (getEngine().getInput().getKeyPressed(SDL_SCANCODE_W)) getEngine().getAudio().PlaySound("snare");
        if (getEngine().getInput().getKeyPressed(SDL_SCANCODE_E)) getEngine().getAudio().PlaySound("open-hat");*/

        /*if (getEngine().getInput().getKeyDown(SDL_SCANCODE_A)) transform.rotation -= math::degtoRad(90) * getEngine().getTime().GetDeltaTime();
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_D)) transform.rotation += math::degtoRad(90) * getEngine().getTime().GetDeltaTime();*/
        float speed = 200;
        viper::vec2 direction{ 0,0 };
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_W)) direction.y = -1;
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_S)) direction.y = 1;
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_A)) direction.x = -1;
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_D)) direction.x = 1;
        
        if (direction.LenghtSqr() > 0)
        {
            direction = direction.Normalized();
            transform.position += (direction * speed) * getEngine().getTime().GetDeltaTime();
        }

        //draw

        vec3 color{ 0,0,0 };
        getEngine().getRenderer().SetColor(color.x, color.y, color.z);
        getEngine().getRenderer().Clear();

        text->Draw(getEngine().getRenderer(), 40.0f, 40.0f);

        vec2 speedz{ -140.0f, 0.0f };
        float lenght = speedz.Lenght();
        for (auto& star : starts) {
            star += speedz * getEngine().getTime().GetDeltaTime();
            if (star[0] > 1280) star[0] = 0;
            if (star[0] < 0) star[0] = 1280;

            getEngine().getRenderer().SetColor((uint8_t)random::getInt(256), random::getInt(256), random::getInt(256));
            getEngine().getRenderer().DrawPoint(star.x, star.y);
        }
                
         //airplaneModel.Draw(renderer,input.GetMousePosition(),time.GetTime(),10.0f);
        airplaneModel.Draw(getEngine().getRenderer(), transform);
       
        if (getEngine().getInput().GetMouseButtonDown(viper::InputSystem::mouseButton::Left)) {
            viper::vec2 pos = getEngine().getInput().GetMousePosition();
            if (points.empty() || (pos - points.back()).Lenght() > 10) {
                points.push_back(pos);
            }
        }

        getEngine().getRenderer().Present();
    }

    getEngine().Shutdown();

    return 0;
}
