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

		bool destroyed{ false }; // Flag to mark if the actor is destroyed
		float lifespan{ 0 }; // Lifespan of the actor, used for destruction

		Transform transform;
		class Scene* scene{ nullptr }; // Pointer to the scene this actor belongs to
	public:
		Actor() = default;
		Actor(const viper::Transform& transfrom, std::shared_ptr<class Model>model):
			transform {transfrom},
			model{model}
		{ }

		virtual void Update(float dt);
		virtual void Draw(class Renderer& renderer);

		virtual void onCollision(Actor* other)= 0;
		float getRadius();

	protected:

		std::shared_ptr<Model> model; // Model associated with the actor
	};
}