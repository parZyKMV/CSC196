#pragma once
#include <memory>
#include "Scene.h"

namespace viper
{
	class Game {
	public:
		Game() = default;
		virtual bool Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(class Renderer& renderer) = 0;

		void addScore(int points) {
			m_score += points;
		}
		int getScore() const {
			return m_score;
		}
		void setLives(int lives) {
			m_lives = lives;
		}
		int getLives() const {
			return m_lives;
		}

	protected:
		int m_score{ 0 }; // Game score
		int m_lives{ 0 }; // Player lives
		std::unique_ptr<class Scene> m_scene; // Pointer to the current scene
	};
}