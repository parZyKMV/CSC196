#pragma once
#include "../Core/Time.h"
#include <memory>

namespace viper {
	class Renderer;
	class AudioSystem;
	class InputSystem;

	class Engine
	{
	public:
		Engine() = default;
		
		bool Initialize();
		void Shutdown();

		void Update();
		void Draw();

		Renderer& getRenderer() { return *m_renderer; }
		AudioSystem& getAudio() { return *m_audio; }
		InputSystem& getInput() { return *m_input; }

		Time& getTime() { return m_time; }

		int m_width = 1280;
		int m_height = 1024;

	private:
		Time m_time;
		std::unique_ptr<Renderer> m_renderer;
		std::unique_ptr<AudioSystem> m_audio;
		std::unique_ptr<InputSystem> m_input;

	};

	Engine& getEngine();
	inline Renderer& getRenderer() { return getEngine().getRenderer(); }
}
