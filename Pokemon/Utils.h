#pragma once
#include "Type.h"
#include <Windows.h>
#include <string>
#include <vector>
#include <iostream>


namespace Utils {

	extern std::vector<std::vector<std::string>> AsciiFont;

	void InitAsciiArt();

	template<typename T>
	T Clamp(T value, T min, T max)
	{
		if (value < min) value = min;
		if (value > max) value = max;
		return value;
	}

	void activerSupportUnicode();

	void setConsoleSizeANSI(int width, int height);

	void SetConsoleToUTF8();

	void PrintTextToArt(std::string text);

	int GetConsoleWidth();

	int GetConsoleHeight();

	void AddChar(int quantity, char c);

	int CalculatePos(int length);

	//Type* StringToType(std::string typeName);
}