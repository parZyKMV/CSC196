#pragma once
#include <SDL3/SDL.h>
#include "iostream"

class Rendeder
{
public:
	Rendeder() = default;

	bool Inatialize();
	bool CreateWindow(const std::string& name, int width, int height);

	void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

private:
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
};
