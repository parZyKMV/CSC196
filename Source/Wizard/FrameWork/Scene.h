#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Actor.h"

namespace viper {
	class Scene {
	public:
		Scene() = default;

		void Update(float dt);
		void Draw(class Renderer& renderer);
		void AddActor(std::unique_ptr<class Actor> actor);
		Actor* GetActorByName(const std::string& name);
	private:
		std::vector <std::unique_ptr<class Actor>> m_actors;
	};
}