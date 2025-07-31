#pragma once
#include "FrameWork/Game.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

class SpaceGame : public viper::Game
{
public:
	enum class GameState
	{
		Initialize,
		Title,
		StartGame,
		StartRound,
		Game,
		PlayerDead,
		GameOver,
	};
public:
	SpaceGame() = default;
	bool Initialize() override;
	void Shutdown() override;
	void Update(float dt) override;
	void Draw(class viper::Renderer& renderer) override;

private:
	GameState m_gameState = GameState::Initialize;
	float enemySpawnTimer = { 0 };

	std::shared_ptr<viper::Font> m_titleFont;
	std::shared_ptr<viper::Font> m_uiFont;

	std::unique_ptr<viper::Text> m_tittleText;
	std::unique_ptr<viper::Text> m_scoreText;
	std::unique_ptr<viper::Text> m_Text;

protected:
};