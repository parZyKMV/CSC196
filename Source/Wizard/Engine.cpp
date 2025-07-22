#include "Renderer/Engine.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "AudioSystem.h"

namespace viper {
	bool Engine::Initialize()
	{
		m_renderer = std::make_unique<Renderer>();
		m_renderer->Inatialize();
		m_renderer->CreateWindow("Viper Engine", m_width, m_height);


		m_input = std::make_unique<InputSystem>();
		m_input->Inatialize();


		m_audio = std::make_unique<AudioSystem>();
		m_audio->Iniatialize();

		return true;
	}

	void Engine::Shutdown()
	{
		m_renderer->ShutDown();
		m_input->ShutDown();
		m_audio->Shutdown();
	}

	void Engine::Draw()
	{

	}

	Engine& getEngine()
	{
		static Engine engine;
		return engine;
	}
}