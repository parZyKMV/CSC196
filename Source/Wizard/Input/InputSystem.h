#pragma once
#include "../Math/Vector2.h"
#include <vector>
#include <array>

namespace viper {
	class InputSystem {
	public:
		InputSystem() = default;
		enum class mouseButton {
			Left,
			Middle,
			Right
		};

		enum class direction {
			Left,
			Right
		};

		bool Inatialize();
		void ShutDown();

		void Update();


		//KEYBOARD INPUT
		bool getKeyDown(uint8_t key) const { return m_keyboardState[key]; }
		bool getPrevKeyDown(uint8_t key) const { return m_prevKeyboardState[key]; }
		bool getKeyPressed(uint8_t key) const { return !m_prevKeyboardState[key] && m_keyboardState[key]; }
		bool getKeyRealesed(uint8_t key) const { return m_prevKeyboardState[key] && !m_keyboardState[key]; }

		const vec2& GetMousePosition() const { return m_mousePosition; }
		const vec2& GetPrevMousePosition() const { return m_prevMousePosition; }

		bool GetMouseButtonDown(mouseButton button) { return m_mouseButtonState[static_cast<size_t>(button)]; }
		bool GetPrevMouseButtonDown(mouseButton button) { return m_prevMouseButtonState[static_cast<size_t>(button)]; }
		bool GetMouseButtonPressed(mouseButton button) { return !m_prevMouseButtonState[static_cast<size_t>(button)] && m_mouseButtonState[static_cast<size_t>(button)]; }
		bool GetMouseButtonReleased(mouseButton button) { return m_prevMouseButtonState[static_cast<size_t>(button)] && !m_mouseButtonState[static_cast<size_t>(button)]; }

	private:
		std::vector<bool> m_keyboardState;
		std::vector<bool> m_prevKeyboardState;

		viper::vec2 m_mousePosition{0,0};
		viper::vec2 m_prevMousePosition{0,0};

		std::array<bool,3> m_mouseButtonState{ false,false,false };
		std::array<bool,3> m_prevMouseButtonState{ false,false,false };

	};
}