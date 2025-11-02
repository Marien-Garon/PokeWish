#include "Button.h"
#include <iostream>


void Button::DysplayButton()
{
	int textLength = (int)text.size() + 2;

	int startPos = Utils::CalculatePos(textLength);

	if (isSelected)
		std::cout << "\033[033m";
	
	Utils::AddChar(startPos,' ');

	Utils::AddChar(textLength, '#');
	std::cout << std::endl;

	Utils::AddChar(startPos, ' ');
	std::cout << "|" << text << "|" << std::endl;

	Utils::AddChar(startPos, ' ');

	Utils::AddChar(textLength, '#');
	std::cout << "\033[0m" << std::endl;
}



void Button::Click()
{
	if (onClick)
	{
		onClick();
	}
}