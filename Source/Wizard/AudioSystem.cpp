#include "AudioSystem.h"
#include <fmod_errors.h>
#include <iostream>

namespace viper {
	bool CheckFMODResult(FMOD_RESULT result) {
		if (result != FMOD_OK) {
			std::cerr << FMOD_ErrorString(result) << std::endl;
			return false;
		}
	}

	bool AudioSystem::Iniatialize() {
		FMOD_RESULT result = FMOD::System_Create(&m_system);
		if (result != FMOD_OK) {
			std::cerr << FMOD_ErrorString(result) << std::endl;
			return false;
		}

		void* extradriverdata = nullptr;
		m_system->init(32, FMOD_INIT_NORMAL, extradriverdata);
		return true;
	}

	bool AudioSystem::Shutdown() {

	}

	void AudioSystem::Update() {

	}
}