#pragma once
#include "iostream"
#include "Renderer.h"
#include "Font.h"
#include "../Math/Vector3.h"

struct SDL_Texture;
namespace viper{
	class Text {
	public:
		Text() = default;
		Text(Font* font) : m_font{ font } {}
		~Text();

		bool Create(Renderer& renderer, const std::string& text, const vec3& color);
		void Draw(Renderer& renderer, float x, float y);

	private:
		Font* m_font{ nullptr };
		SDL_Texture* m_texture{ nullptr };
	};
}
