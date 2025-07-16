#include "../Math/Vector2.h"
#include "../Math/Vector3.h"

#include <vector>

namespace viper {
	class Model {
	public:
		Model() = default;
		Model(const std::vector<vec2> points, const vec3& color):
			m_points{ points },
			m_color{ color }
		{ }
		void Draw(class Renderer& renderer, const vec2& position, float ratation, float scale);

	private:
		std::vector<vec2> m_points;
		vec3 m_color{ 1,1,1 };
	};
}