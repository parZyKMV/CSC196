#include "Player.h"
#include "../Wizard/Renderer/Engine.h"
#include "../Wizard/Input/InputSystem.h"

using namespace viper;
void Player::Update(float dt)
{
	float speed = 200;
	float rotationRate = 100;

	//rotation
	float rotate = 0;
	if (getEngine().getInput().getKeyDown(SDL_SCANCODE_A)) rotate = -1;
	if (getEngine().getInput().getKeyDown(SDL_SCANCODE_D)) rotate = +1;

	vec2 direction{ 1,0 };
	vec2;
	//m_transform.rotation += (rotate * rotationRate) * dt;
}