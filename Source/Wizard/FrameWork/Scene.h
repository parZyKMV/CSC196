#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Actor.h"
#include "../Core/StringHelper.h" 

namespace viper {

	class Renderer;
	class Actor;

	class Scene {
	public:
		Scene() = default;

		void Update(float dt);
		void Draw(Renderer& renderer);
		void AddActor(std::unique_ptr<Actor> actor);

		template<typename T = Actor>
		T* getActorByName(const std::string& name);

		template<typename T = Actor>
		std::vector<T*> getActorsByTag(const std::string& tag);

	private:
		std::vector<std::unique_ptr<Actor>> m_actors;
	};


	template<typename T>
	T* Scene::getActorByName(const std::string& name)
	{
		for (auto& actor : m_actors) {
			if (viper::toLower(actor->name) == viper::toLower(name)) {
				T* object = dynamic_cast<T*>(actor.get());
				if (object) {
					return object;
				}
			}
		}
		return nullptr;
	}

	template<typename T>
	std::vector<T*> Scene::getActorsByTag(const std::string& tag)
	{
		std::vector<T*> results;
		for (auto& actor : m_actors) {
			if (viper::toLower(actor->tag) == viper::toLower(tag)) {
				T* object = dynamic_cast<T*>(actor.get());
				if (object) {
					results.push_back(object);
				}
			}
		}
		return results;
	}

} 
