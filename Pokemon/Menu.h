#pragma once
#include <vector>
#include "Button.h"
#include "Utils.h"
#include "InputManager.h"
#include "GameManager.h"
#include <iostream>

class GameManager;

class Menu
{	
public:
	std::string menuTitle;
	std::vector<std::unique_ptr<Button>> buttonList;
	int selectedIndice = 0;


	Menu(std::string txt) :
		menuTitle(txt) {}


	int GetMaxSizeButton();

	void AddButton(std::unique_ptr<Button> button);
	void DysplayMenu();
	void MoveUp();
	void MoveDown();
	void Select();

	void NavigateToMenu(GameManager* gm, std::function<void()> function = {});
};

