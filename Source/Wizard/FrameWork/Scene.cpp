#include "Scene.h"
#include "Actor.h"
#include <iostream>

namespace viper {

	void Scene::Update(float dt) {
		//update all actors in the scene
		for (auto& actor : m_actors) {
			actor->Update(dt);
		}

		// Remove destroyed actors from the scene
		for(auto iter = m_actors.begin(); iter != m_actors.end();) {
			if ((*iter)->destroyed) {
				// If the actor is destroyed, remove it from the scene
				iter = m_actors.erase(iter);
			} else {
				++iter;
			}
		}

		// Check for collisions between actors
		for (auto& actorA : m_actors) {
			for (auto& actorB : m_actors) {
				if(actorA == actorB || (actorA->destroyed || actorB->destroyed)) {
					continue; // Skip self-collision and destroyed actors
				}
				float distance = (actorA->transform.position - actorB->transform.position).Lenght();
				if(distance <= actorA->getRadius() + actorB->getRadius()) {
					// Collision detected, call onCollision for both actors
					actorA->onCollision(actorB.get());
					actorB->onCollision(actorA.get());
				}
			}
		}
	}

	void Scene::Draw(Renderer& renderer) {
		for (auto& actor : m_actors) {
			actor->Draw(renderer);
		}
	}

	void Scene::AddActor(std::unique_ptr<Actor> actor) {
		actor->scene = this;
		m_actors.push_back(std::move(actor));
	}

} 
