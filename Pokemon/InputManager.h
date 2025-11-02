#pragma once
#include <conio.h>

enum class Input
{
	Up, 
	Down,
	Right,
	Left,
	Select,
	Escape,
	None
};


class InputManager
{
public:
	static Input GetInput();
};

