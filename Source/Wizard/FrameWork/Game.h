#pragma once
#include <memory>

namespace viper
{
	class Game {
	public:
		Game() = default;
		virtual bool Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

	};
}