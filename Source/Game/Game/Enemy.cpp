#include "Enemy.h"
#include "Renderer/Engine.h"
#include "FrameWork/Scene.h"
#include "FrameWork/Game.h"
#include "Renderer/renderer.h"
#include "Rocket.h"
#include "GameData.h"
#include "Renderer/Model.h"
#include <Math/Vector3.h>
#include "Player.h"
#include "Renderer/ParticleSystem.h"
#include "Core/Random.h"


using namespace viper;

void Enemy::Update(float dt)
{
    bool playerSeen = false;

    Player* player = scene->getActorByName<Player>("player");
    if (player) {
        viper::vec2 direction{ 0, 0 };
        direction = player->transform.position - transform.position;

        direction = direction.Normalized();
        viper::vec2 forward = viper::vec2{ 1, 0 }.Rotate(viper::math::degToRad(transform.rotation));

        float angle = viper::math::radToDeg(viper::vec2::AngleBetween(forward, direction));
        playerSeen = angle <= 30;

        if (playerSeen) {
            float angle = viper::vec2::SignedAngleBetween(forward, direction);
            angle = viper::math::sin(angle);
            transform.rotation += viper::math::radToDeg(angle * 5 * dt);
        }
    }

    viper::vec2 force = viper::vec2{ 1, 0 }.Rotate(viper::math::degToRad(transform.rotation)) * speed;
    velocity += force * dt;

    float maxSpeed = 500.0f;
    if (velocity.Lenght() > maxSpeed) {
        velocity = velocity.Normalized() * maxSpeed;
    }

    transform.position.x = viper::math::wrap(transform.position.x, 0.0f, (float)viper::getEngine().getRenderer().GetWidth());
    transform.position.y = viper::math::wrap(transform.position.y, 0.0f, (float)viper::getEngine().getRenderer().GetHeight());

    // check fire
    fireTimer -= dt;
    if (fireTimer <= 0 && playerSeen) {
        fireTimer = fireTime;

        std::shared_ptr<viper::Model> model = std::make_shared<viper::Model>(GameData::rocket, viper::vec3{ 0.0f, 1.0f, 0.0f });
        // spawn rocket at player position and rotation
        viper::Transform transform{ this->transform.position, this->transform.rotation, 2.0f };
        auto rocket = std::make_unique<Rocket>(transform, model);
        rocket->speed = 500.0f;
        rocket->lifespan = 1.5f;
        rocket->name = "rocket";
        rocket->tag = "enemy";

        scene->AddActor(std::move(rocket));
    }

    Actor::Update(dt);
}

void Enemy::onCollision(Actor* other) {
	if (tag != other->tag) {
		// If the rocket collides with something that is not a player, destroy it
		destroyed = true;
		scene->getGame()->addScore(100);// Increase score by 100 points
        viper::Particle particle;
        particle.position = transform.position;
        particle.velocity = random::onUnitCircle() * random::getReal(10.0f, 200.0f);
        particle.color = vec3{ 1,1,1 };
        particle.lifespan = 2;

        viper::getEngine().getParticleSystem().AddParticle(particle);
	}
}