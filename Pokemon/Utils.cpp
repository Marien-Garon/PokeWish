#include "Utils.h"

namespace Utils {

	std::vector<std::vector<const char*>> AsciiFont(128);

	void InitAsciiArt()
	{
		AsciiFont['A'] = { " _____ ", "|  _  |", "|     |", "|__|__|", "       " };
		AsciiFont['B'] = { " _____ ", "| __  |", "| __ -|", "|_____|", "       " };
		AsciiFont['C'] = { " _____ ", "|     |", "|   --|", "|_____|", "       " };
		AsciiFont['D'] = { " ____  ", "|    \\ ","|  |  |", "|____/ ", "       " };
		AsciiFont['E'] = { " _____ ", "|   __|", "|   __|", "|_____|", "       " };
		AsciiFont['F'] = { " _____ ", "|   __|", "|   __|", "|__|   ", "       " };
		AsciiFont['G'] = { " _____ ", "|   __|", "|  |  |", "|_____|", "       " };
		AsciiFont['H'] = { " _____ ", "|  |  |", "|     |", "|__|__|", "       " };
		AsciiFont['I'] = { " _____ ", "|     |", "|-   -|", "|_____|", "       " };
		AsciiFont['J'] = { "    __ ", " __|  |", "|  |  |", "|_____|", "       " };
		AsciiFont['K'] = { " _____ ", "|  |  |", "|    -|", "|__|__|", "       " };
		AsciiFont['L'] = { " __    ", "|  |   ", "|  |__ ", "|_____|", "       " };
		AsciiFont['M'] = { " _____ ", "|     |", "| | | |", "|_|_|_|", "       " };
		AsciiFont['N'] = { " _____ ", "|   | |", "| | | |", "|_|___|", "       " };
		AsciiFont['O'] = { " _____ ", "|     |", "|  |  |", "|_____|", "       " };
		AsciiFont['P'] = { " _____ ", "|  _  |", "|   __|", "|__|   ", "       " };
		AsciiFont['Q'] = { " _____ ", "|     |", "|  |  |", "|__  _|", "   |__|" };
		AsciiFont['R'] = { " _____ ", "| __  |", "|    -|", "|__|__|", "       " };
		AsciiFont['S'] = { " _____ ", "|   __|", "|__   |", "|_____|", "       " };
		AsciiFont['T'] = { " _____ ", "|_   _|", "  | |  ", "  |_|  ", "       " };
		AsciiFont['U'] = { " _____ ", "|  |  |", "|  |  |", "|_____|", "       " };
		AsciiFont['V'] = { " _____ ", "|  |  |", "|  |  |", " \\___/ ","       " };
		AsciiFont['W'] = { " _ _ _ ", "| | | |", "| | | |", "|_____|", "       " };
		AsciiFont['X'] = { " __ __ ", "|  |  |", "|-   -|", "|__|__|", "       " };
		AsciiFont['Y'] = { " __ __ ", "|  |  |", "|_   _|", "  |_|  ", "       " };
		AsciiFont['Z'] = { " _____ ", "|__   |", "|   __|", "|_____|", "       " };
		AsciiFont[' '] = { "       ", "       ", "       ", "       ", "       " };

	}


	void SetConsoleToUTF8()
	{
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
	}

	void PrintTextToArt(std::string text)
	{	
		int startPos = CalculatePos((int)text.size() * 6);

		for (int i = 0; i < 5; ++i)
		{
			std::cout << "|";
			AddChar(startPos-1,' ');
			//std::cout << "|";

			for (int j = 0; j < text.size(); ++j)
			{
				std::cout << AsciiFont[text[j]][i];
			}
			AddChar(GetConsoleWidth() - (startPos + (int)text.size()*7) - 1, ' ');
			std::cout << "|";
			std::cout << std::endl;
		}
	}

	int GetConsoleWidth()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

		return csbi.srWindow.Right - csbi.srWindow.Left + 1;
	}

	int GetConsoleHeight()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

		return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	}

	void AddChar(int quantity, char c)
	{
		for (int space = 0; space < quantity; ++space)
		{
			std::cout << c;
		}
	}

	int CalculatePos(int length)
	{
		return (GetConsoleWidth() - length) / 2;
	}
}

