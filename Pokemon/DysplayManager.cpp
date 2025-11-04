#include "DysplayManager.h"
#include "GameManager.h"

void DysplayManager::TestMenu(GameManager* gm)
{
	Menu testMenu = { "TEST QMENU" };

	testMenu.AddButton(std::make_unique<Button>("Bouton 1",
	[]() {
		std::cout << "Bouton 1 cliqué" << std::endl;
	}));

	testMenu.AddButton(std::make_unique<Button>("Bouton 2",
	[]() {
			std::cout << "Bouton 2 cliqué" << std::endl;
	} ));
	
	testMenu.NavigateToMenu(gm);
}

void DysplayManager::MainMenu(GameManager* gm)
{
	Menu mainMenu = { "POKEWISH" };
	
	mainMenu.AddButton(std::make_unique<Button>("Play",
		[gm]() {
			gm->previousState = gm->state;
			gm->state = GameState::testMenu;
		}
	));

	mainMenu.AddButton(std::make_unique<Button>("Credits",
		[gm]() {
			gm->previousState = gm->state;
			gm->state = GameState::credits;
		}
	));

	mainMenu.AddButton(std::make_unique<Button>("Quit",
		[gm]() {
			gm->Stop();
		}
	));

	mainMenu.AddButton(std::make_unique<Button>("DysplayTest",
		[gm]() {
			gm->previousState = gm->state;
			gm->state = GameState::PokeDysplay;
		}
	));

	mainMenu.AddButton(std::make_unique<Button>("EquipDysplay",
		[gm]() {
			gm->previousState = gm->state;
			gm->state = GameState::EquipDysplay;
		}
	));

	mainMenu.NavigateToMenu(gm);
}

void DysplayManager::CreditsMenu(GameManager* gm)
{
	Menu credits = { "CREDITS " };

	credits.AddButton(std::make_unique<Button>("Quitter Credits",
		[gm]() {
			gm->previousState = gm->state;
			gm->state = GameState::MainMenu;
		}
	));

	credits.NavigateToMenu(gm,
		[]() {
			int startPos = Utils::CalculatePos(25);

			std::cout << std::endl;
			Utils::AddChar(startPos, ' ');
			std::cout << "A peu pres tout : Moi" << std::endl;
			Utils::AddChar(startPos, ' ');
			std::cout << "Il a copié je copie : Eliott" << std::endl;
			Utils::AddChar(startPos, ' ');
			std::cout << "Lenny : Lenny" << std::endl;
		}
	);
}

void DysplayManager::PokeDysplay(GameManager* gm)
{
	Menu PokeMenu = { gm->CurrentPokemon.name };

	PokeMenu.AddButton(std::make_unique<Button>("Back",
		[gm]() {
			gm->previousState = gm->state;
			gm->state = GameState::MainMenu;
		}
	));


	PokeMenu.NavigateToMenu(gm,
		[gm]() 
		{
			gm->CurrentPokemon.DysplayStat();
		}
	);
}

void DysplayManager::DysplayPlayerEquip(GameManager* gm, Player* player)
{
	Menu EquipDysplay = { "Equip" };

	EquipDysplay.AddButton(std::make_unique<Button>("Back",
		[gm]() {
			gm->previousState = gm->state;
			gm->state = GameState::MainMenu;
		}
	));

	for (auto& poke : player->equip)
	{
		EquipDysplay.AddButton(std::make_unique<Button>(poke.name,
			[gm, poke]() {
				gm->previousState = gm->state;
				gm->state = GameState::PokeDysplay;
				gm->CurrentPokemon = poke;
				gm->CurrentPokemon.DysplayStat();
			}
		));
	}

	EquipDysplay.NavigateToMenu(gm);
}