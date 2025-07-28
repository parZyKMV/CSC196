#include "Scene.h"
#include "Actor.h"
#include "../Core/StringHelper.h"
#include "iostream"

namespace viper {
	void Scene::Update(float dt) {
		for (auto& actor : m_actors) {
			actor->Update(dt);
		}
	}

	void Scene::Draw(Renderer& renderer) {
		for (auto& actor : m_actors) {
			actor->Draw(renderer);
		}
	}

	void Scene::AddActor(std::unique_ptr<class Actor> actor) {
		actor->scene = this; // Set the scene pointer for the actor
		m_actors.push_back(std::move(actor));
	}

	Actor* Scene::GetActorByName(const std::string& name) {
		for (auto& actor : m_actors) {
			if (toLower(actor->name) == name) {
				return actor.get();
			}
		}
		return nullptr;
	}
}