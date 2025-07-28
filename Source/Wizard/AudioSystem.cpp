#include "AudioSystem.h"
#include <fmod_errors.h>
#include <fmod.hpp>
#include <iostream>
#include  "Core/StringHelper.h"

namespace viper {
	bool AudioSystem::CheckFMODResult(FMOD_RESULT result) {
		if (result != FMOD_OK) {
			std::cerr << FMOD_ErrorString(result) << std::endl;
			return false;
		}
		return true;
	}

	bool AudioSystem::Iniatialize() {
		FMOD_RESULT result = FMOD::System_Create(&m_system);

		if (!CheckFMODResult(result)) return false;

		void* extradriverdata = nullptr;
		m_system->init(32, FMOD_INIT_NORMAL, extradriverdata);
		if (!CheckFMODResult(result)) return false;
		return true;
	}

	void AudioSystem::Shutdown() {
		CheckFMODResult(m_system->release());
	}

	void AudioSystem::Update() {
		CheckFMODResult(m_system->update());
	}

	bool AudioSystem::AddSound(const std::string& filename, const std::string& name)
	{
		std::string key = (name.empty()) ? filename : name;
		key = viper::toLower(key);

		if (m_sounds.find(key) != m_sounds.end()) {
			std::cerr << "Auido System Alredy exist: " << key << std::endl;
			return false;
		}

		FMOD::Sound* sound = nullptr;
		FMOD_RESULT result = m_system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);
		if (!CheckFMODResult(result)) { return false; }

		m_sounds[key] = sound;
		return true;
	}

	bool AudioSystem::PlaySound(const std::string& name)
	{
		std::string key = name;
		
		for (char& c : key) {
			c = std::tolower(c);
		}

		if (m_sounds.find(key) == m_sounds.end()) {
			std::cerr << "Audio System : name doesn't exist: " << name << std::endl;
			return false;
		}

		FMOD_RESULT result = m_system->playSound(m_sounds[key], 0, false, nullptr);
		if (!CheckFMODResult(result)) { return false;}

		return true;
	}


}