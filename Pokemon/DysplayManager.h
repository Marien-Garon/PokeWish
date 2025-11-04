#pragma once
#include "Menu.h"
#include "Button.h"
#include "InputManager.h"
#include "Player.h"
#include <conio.h>
#include <memory>


class GameManager;

class DysplayManager
{
public:
	void TestMenu(GameManager* gm);

	void MainMenu(GameManager* gm);

	void CreditsMenu(GameManager* gm);

	void PokeDysplay(GameManager* gm);

	void DysplayPlayerEquip(GameManager* gm, Player* player);
};