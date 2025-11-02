#pragma once
#include <vector>
#include "Button.h"
#include "Utils.h"
#include "InputManager.h"
#include <iostream>


class Menu
{	
public:
	std::string menuTitle;
	std::vector<std::unique_ptr<Button>> buttonList;
	int selectedIndice = 0;


	Menu(std::string txt) :
		menuTitle(txt) {}


	void AddButton(std::unique_ptr<Button> button);
	void DysplayMenu();
	void MoveUp();
	void MoveDown();
	void Select();

	void NavigateToMenu(std::function<void()> function = {});
};

