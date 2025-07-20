#pragma once
#include <SDL3/SDL.h>
#include "iostream"

class Renderer
{
public:
	Renderer() = default;

	bool Inatialize();
	void ShutDown();
	bool CreateWindow(const std::string& name, int width, int height);

	void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
	void SetColor(float r, float g, float b, float a = 1.0f);
	void Clear();

	void Present();
	void DrawLine(float x1, float y1, float x2, float y2);
	void DrawPoint(float x, float y);

private:
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
};
