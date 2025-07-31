#include "Model.h"
#include "Renderer.h"

namespace viper {

	void Model::Draw(Renderer& renderer, const vec2& position, float rotation, float scale) {
		if (m_points.empty()) return;

		renderer.SetColor(m_color.x, m_color.y, m_color.z);

		
		for (int i = 0; i < m_points.size(); i++) {
			vec2 p1 = m_points[i].Rotate(rotation) * scale + position;
			vec2 p2 = m_points[(i + 1) % m_points.size()].Rotate(rotation) * scale + position; 

			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
	
	void Model::Draw(Renderer& renderer, const Transform& transform)
	{
		Draw(renderer, transform.position, transform.rotation, transform.scale);
	}

	void Model::calculateRadius() {
		m_radius = 0;
		for (auto& point : m_points) {
			float lenght = point.Lenght();
			if (lenght > m_radius) {
				m_radius = lenght;
			}
		}
	}
}