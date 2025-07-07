#include <SDL3/SDL.h>
#include <iostream>
#include <cstdlib>   

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Project", 1280, 1024, 0);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    bool quit = false;

    // Green rectangle


    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);

        // Draw 10 random red lines
        for (int i = 0; i < 10; ++i) {
            float x1 = rand() % 1000;
            float y1 = rand() % 1000;
            float x2 = rand() % 1000;
            float y2 = rand() % 1000;


        //Random colors
            Uint8 r = rand() % 256;
            Uint8 g = rand() % 256;
            Uint8 b = rand() % 256;

            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderLine(renderer, x1, y1, x2, y2);
        }

        //Draw 20 random points
        for (int i = 0; i < 20; i++)
        {
            float x = rand() % 1000;
            float y = rand() % 1000;

            //Random colors
            Uint8 r = rand() % 256;
            Uint8 g = rand() % 256;
            Uint8 b = rand() % 256;

            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderPoint(renderer, x, y);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
