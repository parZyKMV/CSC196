#pragma once
#include "FrameWork/Actor.h"
#include "Renderer/Model.h"


class Rocket : public viper::Actor {
public:
	float speed = 200;
public:
	Rocket() = default;
	Rocket(const viper::Transform& transform, std::shared_ptr<viper::Model> model) :
		Actor{ transform,model }{ }
	void Update(float dt) override;
	void onCollision(Actor* other) override;
};