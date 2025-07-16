#include "Model.h"
#include "Renderer.h"

namespace viper {
	void Model::Draw(Renderer& renderer, const vec2& position, float rotation, float scale) {
		if (m_points.empty()){return;}

		renderer.SetColor(m_color.x,m_color.y,m_color.z);

		for (int i = 0; i < m_points.size() - 1 ; i++)
		{
			vec2 p1 = m_points[i] + position * scale;
			vec2 p2 = m_points[i + 1] + position * scale;

			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}



}