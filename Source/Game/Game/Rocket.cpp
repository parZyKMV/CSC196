#include "Rocket.h"
#include "../Wizard/Renderer/Engine.h"
#include "../Wizard/FrameWork/Scene.h"
#include "Renderer/renderer.h"
#include "Player.h"

void Rocket::Update(float dt) {
	viper::vec2 force = viper::vec2{ 1, 0 }.Rotate(viper::math::degToRad(transform.rotation)) * speed;
	velocity = force;

	transform.position.x = viper::math::wrap(transform.position.x, 0.0f, (float)viper::getEngine().getRenderer().GetWidth());
	transform.position.y = viper::math::wrap(transform.position.y, 0.0f, (float)viper::getEngine().getRenderer().GetHeight());

	Actor::Update(dt);
}

void Rocket::onCollision(Actor* other) {
	if(tag != other->tag) {
		// If the rocket collides with something that is not a player, destroy it
		destroyed = true;
	}
	std::cout << other->tag << std::endl;
}