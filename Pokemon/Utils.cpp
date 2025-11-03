#include "Utils.h"

namespace Utils {

	std::vector<std::vector<std::string>> AsciiFont(128);

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
		AsciiFont['I'] = { "  ___  ", " |   | ", " |- -| ", " |___| ", "       " };
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

		AsciiFont['a'] = { "     ", " ___ ", "| .'|", "|__,|", "     " };
		AsciiFont['b'] = { " _   ", "| |_ ", "| . |", "|___|", "     " };
		AsciiFont['c'] = { "     ", " ___ ", "|  _|", "|___|", "     " };
		AsciiFont['d'] = { "   _ ", " _| |", "| . |", "|___|", "     " };
		AsciiFont['e'] = { "     ", " ___ ", "| -_|", "|___|", "     " };
		AsciiFont['f'] = { " ___ ", "|  _|", "|  _|", "|_|  ", "     " };
		AsciiFont['g'] = { "     ", " ___ ", "| . |", "|_  |", "|___|" };
		AsciiFont['h'] = { " _   ", "| |_ ", "|   |", "|_|_|", "     " };
		AsciiFont['i'] = { "  _  ", " |_| ", " | | ", " |_| ", "     " };
		AsciiFont['j'] = { "   _ ", "  |_|", "  | |", " _| |", "|___|" };
		AsciiFont['k'] = { " _   ", "| |_ ", "| '_|", "|_,_|", "     " };
		AsciiFont['l'] = { "  _  ", " | | ", " | | ", " |_| ", "     " };
		AsciiFont['m'] = { "      ", " _____ ", "|     |", "|_|_|_|", "      " };
		AsciiFont['n'] = { "     ", " ___ ", "|   |", "|_|_|", "     " };
		AsciiFont['o'] = { "     ", " ___ ", "| . |", "|___|", "     " };
		AsciiFont['p'] = { "     ", " ___ ", "| . |", "|  _|", "|_|  " };
		AsciiFont['q'] = { "     ", " ___ ", "| . |", "|_  |", "  |_|" };
		AsciiFont['r'] = { "     ", " ___ ", "|  _|", "|_|  ", "     " };
		AsciiFont['s'] = { "     ", " ___ ", "|_ -|", "|___|", "     " };
		AsciiFont['t'] = { " _   ", "| |_ ", "|  _|", "|_|  ", "     " };
		AsciiFont['u'] = { "     ", " _ _ ", "| | |", "|___|", "     " };
		AsciiFont['v'] = { "     ", " _ _ ", "| | |", " \\_/ ", "     " };
		AsciiFont['w'] = { "      ", " _ _ _ ", "| | | |", "|_____|", "      " };
		AsciiFont['x'] = { "     ", " _ _ ", "|_'_|", "|_,_|", "     " };
		AsciiFont['y'] = { "     ", " _ _ ", "| | |", "|_  |", "|___|" };
		AsciiFont['z'] = { "     ", " ___ ", "|- _|", "|___|", "     " };

	}

	void activerSupportUnicode() {
		// 1. Définir la page de code en UTF-8
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);

		// 2. Activer le mode de traitement virtuel du terminal (pour ANSI)
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hOut == INVALID_HANDLE_VALUE) return;

		DWORD dwMode = 0;
		if (!GetConsoleMode(hOut, &dwMode)) return;

		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
	}

	void setConsoleSizeANSI(int width, int height) {
		// Séquence : ESC[8;lignes;colonnes;t
		std::cout << "\033[8;" << height << ";" << width << "t" << std::flush;
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

			int charSize = 0;

			for (int j = 0; j < text.size(); ++j)
			{
				std::cout << AsciiFont[text[j]][i];
				charSize += AsciiFont[text[j]][i].size();
			}
			AddChar(GetConsoleWidth() - (startPos + charSize) - 1, ' ');
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

	//Type* StringToType(std::string typeName)
	//{

	//}
}

