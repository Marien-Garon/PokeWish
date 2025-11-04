#include "Pokemon.h"

void Pokemon::DysplayStat()
{
	int startPos = Utils::CalculatePos(11);

	Utils::AddChar(startPos, ' ');
	std::cout << "Type 1 : " << type[0]->name << std::endl;

	if (type.size() > 1)
	{
		Utils::AddChar(startPos, ' ');
		std::cout << "Type 2 : " << type[1]->name << std::endl;
	}
 
	Utils::AddChar(startPos, ' ');
	std::cout << "HP : " << hp << std::endl;


	Utils::AddChar(startPos, ' ');
	std::cout << "Atk : " << atk << std::endl;


	Utils::AddChar(startPos, ' ');
	std::cout << "Def : " << def << std::endl;


	Utils::AddChar(startPos, ' ');
	std::cout << "DefSpe : " << defspe << std::endl;


	Utils::AddChar(startPos, ' ');
	std::cout << "AtkSpe : " << atkspe << std::endl;


	Utils::AddChar(startPos, ' ');
	std::cout << "Speed : " << speed << std::endl;
}