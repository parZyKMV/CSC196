#include "Actor.h"
#include "../Renderer/Model.h"

namespace viper {
	void viper::Actor::Update(float dt)
	{
		if (destroyed)return;

		if (lifespan != 0) {
			lifespan -= dt;
		
			destroyed = lifespan <= 0;
		}

		transform.position += velocity * dt;
		velocity += (1.0f / (1.0f + damping * dt));
	}

	void viper::Actor::Draw(Renderer& renderer)
	{
		if (destroyed)return;

		model->Draw(renderer, transform);
	}

	float Actor::getRadius()
	{
		return model ? model->getRadius() * transform.scale : 0;
	}
}