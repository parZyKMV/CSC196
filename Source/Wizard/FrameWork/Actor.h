#pragma once
#include "../Math/Transform.h"
#include <memory>
#include <string>

namespace viper {
	class Actor {
	public:
		std::string name;
		std::string tag;

		vec2 velocity{ 0,0 };
		float damping{ 0.2f }; // Damping factor for velocity

		class Scene* scene{ nullptr }; // Pointer to the scene this actor belongs to
	public:
		Actor() = default;
		Actor(const viper::Transform& transfrom, std::shared_ptr<class Model>model):
			m_transform {transfrom},
			m_model{model}
		{ }

		virtual void Update(float dt);
		virtual void Draw(class Renderer& renderer);

		Transform& GetTransform() { return m_transform; }
	protected:
		Transform m_transform;
		std::shared_ptr<Model> m_model;
	};
}