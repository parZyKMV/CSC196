#pragma once
#include <fmod.hpp>

namespace viper {
	class AudioSystem
	{
	public:
		AudioSystem() = default;
		
		bool Iniatialize();
		bool Shutdown();

		void Update();

	private:
		bool CheckFMODResult(FMOD_RESULT result);
		FMOD::System* m_system = nullptr;
	};
}