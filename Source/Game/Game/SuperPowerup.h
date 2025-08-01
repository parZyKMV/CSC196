#pragma once
#include "FrameWork/Actor.h"

class SpeedPowerup : public viper::Actor {
public:
    using Actor::Actor;

    void Update(float dt) override;
    void onCollision(Actor* other) override;

    float duration = 5.0f;
};