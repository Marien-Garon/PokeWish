#include "GameManager.h"


void GameManager::Stop()
{
	running = false;
}


void GameManager::Init()
{
	typeManage.InitType();

	pokeManage.InitialisePokemon(&typeManage);

	Utils::InitAsciiArt();
	state = GameState::MainMenu;
	running = true;

	CurrentPokemon = pokeManage.SearchPokemonByID(4);
	Pokemon poke1 = pokeManage.SearchPokemonByName("Salameche");
	Pokemon poke2 = pokeManage.SearchPokemonByName("Tortank");

	player.AddPokemon({ poke1,poke2 });
}


void GameManager::Loop()
{
	DysplayManager dm;

	while (running)
	{
		switch (state)
		{
		case GameState::testMenu:
			dm.TestMenu(this);
			//previousState = GameState::testMenu;
			break;
		case GameState::MainMenu:
			dm.MainMenu(this);
			//previousState = GameState::MainMenu;
			break;
		case GameState::credits:
			dm.CreditsMenu(this);
			//previousState = GameState::credits;
			break;
		case GameState::PokeDysplay:
			dm.PokeDysplay(this);
			//previousState = GameState::PokeDysplay;
			break;
		case GameState::EquipDysplay:
			dm.DysplayPlayerEquip(this, &player);
		}
	}
}


void GameManager::Shutdown()
{
	system("cls");
}