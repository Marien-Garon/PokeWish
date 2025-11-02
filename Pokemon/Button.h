#pragma once
#include "Utils.h"
#include <string>
#include <functional>


class Button
{
public:
	std::string text;
	bool isSelected = false;
	std::function<void()> onClick;
	
	Button(std::string txt, std::function<void()> f, bool select = false) :
		text(txt),
		onClick(f),
		isSelected(select) {}


	void DysplayButton();

	void Click();
};

