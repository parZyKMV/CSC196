#include "Enemy.h"
#include "Renderer/Engine.h"
#include "FrameWork/Scene.h"
#include "FrameWork/Game.h"
#include "Renderer/renderer.h"
#include "Player.h"


using namespace viper;

void Enemy::Update(float dt) {
	speed = 100.0f; // Speed of the enemy

	Actor* player = scene->getActorByName("player");
	if (player) {
		viper::vec2 direction{ 0, 0 };
		direction = player->transform.position - transform.position;
		direction = direction.Normalized(); // Normalize the direction vector
		transform.rotation = math::radToDeg(direction.Angle()); // Set the rotation to face the player
	}

	vec2 direction{ 1, 0 };
	viper::vec2 force = viper::vec2{ 1, 0 }.Rotate(math::degToRad(transform.rotation)) * speed;
	velocity += force * dt;

	transform.position.x = math::wrap(transform.position.x, 0.0f, (float)getEngine().getRenderer().GetWidth());
	transform.position.y = math::wrap(transform.position.y, 0.0f, (float)getEngine().getRenderer().GetHeight());

	Actor::Update(dt);

}

void Enemy::onCollision(Actor* other) {
	if (tag != other->tag) {
		// If the rocket collides with something that is not a player, destroy it
		destroyed = true;
		scene->getGame()->addScore(100);// Increase score by 100 points
	}
}