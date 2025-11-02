#include "DysplayManager.h"
#include "GameManager.h"

void DysplayManager::TestMenu()
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
	
	testMenu.NavigateToMenu();
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

	mainMenu.NavigateToMenu();
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

	credits.NavigateToMenu(
		[]() {
			int startPos = Utils::CalculatePos(25);

			std::cout << std::endl;
			Utils::AddChar(startPos, ' ');
			std::cout << "A peu pres tout : Moi" << std::endl;
			Utils::AddChar(startPos, ' ');
			std::cout << "Il a copie je copie : Eliott" << std::endl;
			Utils::AddChar(startPos, ' ');
			std::cout << "Lenny : Lenny" << std::endl;
		}
	);
}
