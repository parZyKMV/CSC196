#include "InputSystem.h"
#include <SDL3/SDL.h>

namespace viper {
	bool InputSystem::Inatialize() {
		int numKeys;
		const bool* keyboardState = SDL_GetKeyboardState(&numKeys);
		
		m_keyboardState.resize(numKeys);
		std::copy(keyboardState, keyboardState + numKeys, m_keyboardState.begin());
		m_prevKeyboardState = m_keyboardState;

		SDL_GetMouseState(&m_mousePosition.x, &m_mousePosition.y);
		m_prevMousePosition = m_mousePosition;

		return true;
	}

	void InputSystem::ShutDown() {

	}

	void InputSystem::Update() {
		//Keyboard input
		m_prevKeyboardState = m_keyboardState;
		const bool* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_keyboardState.size(), m_keyboardState.begin());


		//Mouse input
		m_prevMousePosition = m_mousePosition;

		m_prevMouseButtonState = m_mouseButtonState;
		uint32_t mouseButtomState = SDL_GetMouseState(&m_mousePosition.x, &m_mousePosition.y);

		m_mouseButtonState[static_cast<size_t>(mouseButton::Left)] = mouseButtomState & SDL_BUTTON_LMASK;
		m_mouseButtonState[static_cast<size_t>(mouseButton::Middle)] = mouseButtomState & SDL_BUTTON_MMASK;
		m_mouseButtonState[static_cast<size_t>(mouseButton::Right)] = mouseButtomState & SDL_BUTTON_RMASK;
	}
}