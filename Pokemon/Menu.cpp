#include "Menu.h"


void Menu::AddButton(std::unique_ptr<Button> button)
{
	buttonList.push_back(std::move(button));
}

void Menu::DysplayMenu()
{
	Utils::PrintTextToArt(menuTitle);

	std::cout << "#";
	Utils::AddChar(Utils::GetConsoleWidth()-2, '-');
	std::cout << "#" << std::endl;

	for (int i = 0; i < buttonList.size(); i++) //auto& button : buttonList
	{
		buttonList[i]->isSelected = false;
		
		if (i == selectedIndice)
		{
			buttonList[i]->isSelected = true;
		}

		buttonList[i]->DysplayButton();
	}
}

void Menu::MoveUp() 
{
	selectedIndice = Utils::Clamp(selectedIndice - 1, 0, (int)buttonList.size() - 1);
}

void Menu::MoveDown()
{
	selectedIndice = Utils::Clamp(selectedIndice + 1, 0, (int)buttonList.size() - 1);
}

void Menu::Select()
{
	system("cls");
	buttonList[selectedIndice]->Click();
}

void Menu::NavigateToMenu(std::function<void()> function)
{
	int notSelected = true;

	while (notSelected)
	{
		system("cls");
		DysplayMenu();

		if (function)
			function();

		switch (InputManager::GetInput())
		{
		case Input::Up:
			MoveUp();
			break;
		case Input::Down:
			MoveDown();
			break;
		case Input::Select:
			Select();
			notSelected = false;
			break;
		//case Input::Escape:
		//	GameState tempState = gm->state;
		//	gm->state = gm->previouState;
		//	gm->previousState = tempState;
		//	notSelected = true;
		//	break;
		}

	}


}