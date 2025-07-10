#include "../Wizard/Renderer/Renderer.h"
#include <iostream>

using namespace std;

bool Renderer::Inatialize() {
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		cerr << "SDL_Init Error: " << SDL_GetError() << endl;
		return false;
	}
	return true;
}

void Renderer::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool Renderer::CreateWindow(const std::string& name, int width, int height)
{
    SDL_Window* window = SDL_CreateWindow("SDL3 Project", 1280, 1024, 0);
    if (m_window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (m_renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    return true;
}

void Renderer::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
    //a -> trasparency
}

void Renderer::Clear()
{
    SDL_RenderClear(m_renderer);
}

void Renderer::Present()
{
    SDL_RenderPresent(m_renderer);
}

void Renderer::DrawLine(float x1, float y1, float x2, float y2)
{
    SDL_RenderLine(m_renderer, x1, y1, x2, y2);
}

void Renderer::DrawPoint(float x, float y)
{
    SDL_RenderPoint(m_renderer, x, y);
}
