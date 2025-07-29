#include "Player.h"
#include "../Wizard/Renderer/Engine.h"
#include "../Wizard/Input/InputSystem.h"

using namespace viper;
void Player::Update(float dt)
{
	speed = 200;
	rotationRate = 100;

	//rotation
	float rotate = 0;
	if (getEngine().getInput().getKeyDown(SDL_SCANCODE_A)) rotate = -1;
	if (getEngine().getInput().getKeyDown(SDL_SCANCODE_D)) rotate = +1;

	m_transform.rotation += (rotate * rotationRate) * dt;

	//thrust
	float thrust = 0;
	if (getEngine().getInput().getKeyDown(SDL_SCANCODE_W)) thrust = -1;
	if (getEngine().getInput().getKeyDown(SDL_SCANCODE_S)) thrust = +1;

	vec2 direction{ 1,0 };
	vec2 force = direction.Rotate(math::degToRad(m_transform.rotation)) * thrust * speed;
	velocity += force * dt;

	m_transform.position.x = math::wrap(m_transform.position.x, 0.0f, (float)getEngine().getRenderer().GetWidth());
	m_transform.position.y = math::wrap(m_transform.position.y, 0.0f, (float)getEngine().getRenderer().GetHeight());


	Actor::Update(dt);
}