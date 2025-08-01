#pragma once
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "../Math/Transform.h"
#include "../Renderer/Renderer.h"

#include <vector>

namespace viper {
	class Model {
	public:
		Model() = default;
		Model(const std::vector<vec2> points, const vec3& color):
			m_points{ points },
			m_color{ color } {
			calculateRadius();
		}
		void Draw(class Renderer& renderer, const vec2& position, float rotation, float scale);
		void Draw(class Renderer& renderer, const Transform& treansform);

		float getRadius() const { return m_radius; }

	private:
		void calculateRadius();
	private:
		float m_radius{ 0 };
		std::vector<vec2> m_points;
		vec3 m_color{ 1,1,1 };
	};
}