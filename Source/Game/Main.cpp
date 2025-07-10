#include "../Wizard/Math/Math.h"
#include "../Wizard/Math/Vector2.h"
#include "../Wizard/Core/Random.h"
#include "../Wizard/Renderer/Renderer.h"



#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>   

int main(int argc, char* argv[]) {
    Renderer renderer;
    
    renderer.Inatialize();
    renderer.CreateWindow("Viper Engine", 1280, 1024);

    SDL_Event e;
    bool quit = false;

    //create start
    std::vector<viper::vec2> starts;
    for (int i = 0;i < 100;i++)
    {
        starts.push_back(viper::vec2{rand() % 1280, rand() % 1024});
    }
    //vec2 v(30, 40);

    // Green rectangle


    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, 255);
        renderer.Clear();

    

        viper::vec2 speed(-0.1f, 0.0f);
        float lenght = speed.Lenght();

        for (auto& star : starts) {
            star += speed;

            if (star[0] > 1280)star[0] = 0;
            if (star[0] < 0) star[0] = 1280;

            renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, 255);
            float x = rand() % 1000;
            float y = rand() % 1000;
            renderer.DrawPoint(star.x, star.y);
        }

        for (int i = 0; i < starts.size(); i++)
        {

        }

        //// Draw 10 random red lines
        //for (int i = 0; i < 10; ++i) {
        //    float x1 = rand() % 1000;
        //    float y1 = rand() % 1000;
        //    float x2 = rand() % 1000;
        //    float y2 = rand() % 1000;


        ////Random colors
        //    Uint8 r = rand() % 256;
        //    Uint8 g = rand() % 256;
        //    Uint8 b = rand() % 256;

        //    renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, 255);
        //    renderer.DrawLine(x1, y1, x2, y2);
        //}

        ////Draw 20 random points
        //for (int i = 0; i < 20; i++)
        //{
    

        //    //Random colors
        //    Uint8 r = rand() % 256;
        //    Uint8 g = rand() % 256;
        //    Uint8 b = rand() % 256;

        //    renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, 255);
        //    
        //}

        renderer.Present();
    }

    renderer.ShutDown();

    return 0;
}
