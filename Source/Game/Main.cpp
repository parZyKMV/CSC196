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
#include "Renderer/Engine.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Core/File.h"
#include "FrameWork/Scene.h"
#include "FrameWork/Actor.h"

#include "Game/SpaceGame.h"
#include "Game/Player.h"


#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>   
#include <fmod.hpp>
#include <memory>

using namespace viper;

int main(int argc, char* argv[]) {

	// Initialize Engine
    getEngine().Initialize();


	//Iniatialize Game
	std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();
	game->Initialize();

    SDL_Event e;
    bool quit = false;

    std::vector<vec2> points; 

    // iniatilize sounds
    getEngine().getAudio().AddSound("bass.wav", "bass");
    getEngine().getAudio().AddSound("snare.wav", "snare");
    getEngine().getAudio().AddSound("open-hat.wav", "open-hat");
     
    //create starts
    std::vector<vec2> starts;
    for (int i = 0; i < 100; i++) {
        starts.push_back(viper::vec2{
            viper::random::getReal() * 1280,
            viper::random::getReal() * 1024
            });
    }


    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        getEngine().Update();
        game->Update(getEngine().getTime().GetDeltaTime());

        if (getEngine().getInput().getKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        //draw

        vec3 color{ 0,0,0 };
        getEngine().getRenderer().SetColor(color.x, color.y, color.z);
        getEngine().getRenderer().Clear();

        vec2 speedz{ -140.0f, 0.0f };
        float lenght = speedz.Lenght();
        for (auto& star : starts) {
            star += speedz * getEngine().getTime().GetDeltaTime();
            if (star[0] > 1280) star[0] = 0;
            if (star[0] < 0) star[0] = 1280;

            getEngine().getRenderer().SetColor((uint8_t)random::getInt(256), random::getInt(256), random::getInt(256));
            getEngine().getRenderer().DrawPoint(star.x, star.y);
        } 

        game->Draw(getEngine().getRenderer());
        getEngine().getRenderer().Present();
    }

    game->Shutdown();
    game.release();
    getEngine().Shutdown();

    return 0;
}
