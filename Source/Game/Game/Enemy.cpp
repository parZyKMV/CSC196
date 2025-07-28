#include "Enemy.h"
#include "../Wizard/Renderer/Engine.h"
#include "../Wizard/FrameWork/Scene.h"	


using namespace viper;

void Enemy::Update(float dt) {
	speed = 100.0f; // Speed of the enemy

	Actor* player = scene->GetActorByName("player");
	if (player) {
		viper::vec2 direction{ 0, 0 };
		direction = player->GetTransform().position - m_transform.position;
		direction = direction.Normalized(); // Normalize the direction vector
		m_transform.rotation = math::radToDeg(direction.Angle()); // Set the rotation to face the player
	}

	vec2 direction{ 1, 0 };
	viper::vec2 force = viper::vec2{ 1, 0 }.Rotate(math::degtoRad(m_transform.rotation)) * speed;
	velocity += force * dt;

	Actor::Update(dt);

	m_transform.position.x = math::wrap(m_transform.position.x, 0.0f, (float)getEngine().getRenderer().GetWidth());
	m_transform.position.y = math::wrap(m_transform.position.y, 0.0f, (float)getEngine().getRenderer().GetHeight());

}