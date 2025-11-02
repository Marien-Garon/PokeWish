#pragma once
#include "Utils.h"
#include "DysplayManager.h"
#include "PokemonManager.h"

enum class GameState
{
	testMenu,
	MainMenu,
	credits
};

class GameManager
{
public:

	bool running;
	GameState state;
	GameState previousState;

	PokemonManager pokeManage;

	void Stop();

	void Init();
	void Loop();
	void Shutdown();
};

