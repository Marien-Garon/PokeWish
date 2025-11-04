#include "Button.h"
#include <iostream>


void Button::DysplayButton(int maxButtonLength)
{
	int textLength = (int)text.size();
	int length = maxButtonLength + 2;
	int startPos = Utils::CalculatePos(length);

	if (isSelected)
		std::cout << "\033[033m";
	
	Utils::AddChar(startPos,' ');

	Utils::AddChar(length, '#');
	std::cout << std::endl;

	Utils::AddChar(startPos, ' ');
	std::cout << "|";
	Utils::AddChar((length - textLength - 2) / 2, ' '); 
	std::cout << text;
	//int truc = (length - textLength - 2) / 2 + ((((length - textLength - 2) / 2) % 2 != 0) ? 1 : 0);
	int tempLength = (length - textLength - 2) / 2;
	if (text.size() % 2 != 0)
		tempLength++;
	Utils::AddChar(tempLength, ' ');
	std::cout << "|" << std::endl;
	//"|" << std::endl;

	Utils::AddChar(startPos, ' ');

	Utils::AddChar(length, '#');
	std::cout << "\033[0m" << std::endl;
}



void Button::Click()
{
	if (onClick)
	{
		onClick();
	}
}