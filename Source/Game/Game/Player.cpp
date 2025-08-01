#include "Player.h"
#include "Rocket.h"
#include "GameData.h"
#include "Renderer/Engine.h"
#include "Renderer/Renderer.h"
#include "FrameWork/Scene.h"
#include "Math/Vector3.h"
#include "Input/InputSystem.h"

using namespace viper;
void Player::Update(float dt)
{

	//rotation
	float rotate = 0;
	if (getEngine().getInput().getKeyDown(SDL_SCANCODE_A)) rotate = -1;
	if (getEngine().getInput().getKeyDown(SDL_SCANCODE_D)) rotate = +1;


	transform.rotation += (rotate * rotationRate) * dt;

	//thrust
	float thrust = 0;
	if (getEngine().getInput().getKeyDown(SDL_SCANCODE_W)) thrust = +1;
	if (getEngine().getInput().getKeyDown(SDL_SCANCODE_S)) thrust = -1;


	vec2 direction{ 1,0};
	vec2 force = direction.Rotate(math::degToRad(transform.rotation)) * thrust * speed;
	velocity += force * dt;

	velocity *= 0.8f; 

	float maxSpeed = 500.0f;
	if (velocity.Lenght() > maxSpeed) {
		velocity = velocity.Normalized() * maxSpeed;
	}

	transform.position.x = math::wrap(transform.position.x, 0.0f, (float)getEngine().getRenderer().GetWidth());
	transform.position.y = math::wrap(transform.position.y, 0.0f, (float)getEngine().getRenderer().GetHeight());

	//check for input to shoot
	fireTimer -= dt;

	if(viper::getEngine().getInput().getKeyPressed(SDL_SCANCODE_SPACE) && fireTimer <= 0) {
		fireTimer = fireTime;
		std::shared_ptr<viper::Model> model = std::make_shared<viper::Model>(GameData::rocket, viper::vec3{ 1.0f, 1.0f, 1.0f });
		//spawn rocket at the player's position and rotation
		viper::Transform transform{this->transform.position, this->transform.rotation,2.0f};
		auto rocket = std::make_unique<Rocket>(transform, model);
		rocket->speed = 1500.0f;
		rocket->lifespan = 1.5f; // Set lifespan for the rocket
		rocket->name = "rocket";
		rocket->tag = "player";

		scene->AddActor(std::move(rocket));
	}

	Actor::Update(dt);
}

void Player::onCollision(Actor* other) {
	if (tag != other->tag) {
		// If the rocket collides with something that is not a player, destroy it
		//destroyed = true;
	}
}