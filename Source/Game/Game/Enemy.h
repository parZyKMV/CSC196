#pragma once
#include "FrameWork/Actor.h"

class Enemy : public viper::Actor {
public:
	float speed;
	Enemy() = default;
	Enemy(const viper::Transform& transform, std::shared_ptr<viper::Model> model) :
		Actor{ transform,model } {
	}

	void Update(float dt) override;
private:

};

