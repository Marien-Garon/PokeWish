#include "InputManager.h"

//int const KEY_UP = 72;
//int const KEY_DOWN = 80;
//int const KEY_LEFT = 75;
//int const KEY_RIGHT = 77;
//int const ENTER = 13;
//int const ESC = 27;



Input InputManager::GetInput()
{
	int key = _getch();
	switch (key)
	{
	case('Z'): case('z'): case 72:
		return Input::Up;
	case 80:
		return Input::Down;
	case 75:
		return Input::Left;
	case 77:
		return Input::Right;
	case 13:
		return Input::Select;
	case 27:
		return Input::Escape;
	default:
		return Input::None;
	}
}