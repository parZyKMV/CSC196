#pragma once
#include "FrameWork/Actor.h"

class Enemy : public viper::Actor {
public:
	float speed = 200;
	float fireTimer = 0;
	float fireTime = 0;
	Enemy() = default;
	Enemy(const viper::Transform& transform, std::shared_ptr<viper::Model> model) :
		Actor{ transform,model } {
	}

	void Update(float dt) override;
	// Handle collision with other actors
	void onCollision(Actor* other) override;
};

