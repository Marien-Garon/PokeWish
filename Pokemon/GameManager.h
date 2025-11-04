#pragma once
#include "Utils.h"
#include "DysplayManager.h"
#include "PokemonManager.h"
#include "TypeManager.h"
#include "Player.h"

enum class GameState
{
	testMenu,
	MainMenu,
	credits,
	PokeDysplay,
	EquipDysplay
};

class GameManager
{
public:

	bool running;
	GameState state;
	GameState previousState;

	Player player;

	TypeManager typeManage;

	PokemonManager pokeManage;

	Pokemon CurrentPokemon;

	void Stop();

	void Init();
	void Loop();
	void Shutdown();
};

