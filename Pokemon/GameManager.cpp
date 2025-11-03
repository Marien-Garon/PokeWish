#include "GameManager.h"


void GameManager::Stop()
{
	running = false;
}


void GameManager::Init()
{
	pokeManage.InitialisePokemon();

	Utils::SetConsoleToUTF8();
	Utils::InitAsciiArt();
	state = GameState::MainMenu;
	running = true;

	CurrentPokemon = pokeManage.SearchPokemonByID(3);
}


void GameManager::Loop()
{
	DysplayManager dm;

	while (running)
	{
		switch (state)
		{
		case GameState::testMenu:
			dm.TestMenu();
			break;
		case GameState::MainMenu:
			dm.MainMenu(this);
			break;
		case GameState::credits:
			dm.CreditsMenu(this);
			break;
		case GameState::PokeDysplay:
			dm.PokeDysplay(this);
			break;
		}
	}
}


void GameManager::Shutdown()
{
	system("cls");
}