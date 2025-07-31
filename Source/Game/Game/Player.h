#pragma once
#include "FrameWork/Actor.h"
//#include "Renderer/Model.h"


class Player : public viper::Actor {
public:
	float speed;
	float rotationRate;
	float fireTime = 0.2f;
	float fireTimer = 0.0f;
	Player() = default;
	Player(const viper::Transform& transform, std::shared_ptr<viper::Model> model) :
		Actor{ transform,model }{ }
	void Update(float dt) override;
	void onCollision(Actor* other) override;
};
