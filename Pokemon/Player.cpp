#include "Player.h"


void Player::AddPokemonByName(std::string name)
{
	//if (equip.size() <= 6)
	//	equip.push_back();
}

void Player::AddPokemonByID(int id)
{
	//if (equip.size() <= 6)
	//	equip.push_back();
}

void Player::AddPokemon(std::initializer_list<Pokemon> pokeList)
{
	for (Pokemon poke : pokeList)
	{
		if (equip.size() <= 6)
			equip.push_back(poke);
	}
}

void Player::DysplayEquip()
{
	int startPos = Utils::CalculatePos(10);
	for (int i = 0; i < equip.size(); ++i)
	{
		int length = (int)equip[i].name.size() + 2;
		Utils::AddChar(startPos, ' ');
		Utils::AddChar(length, '-');
		std::cout << std::endl;
		Utils::AddChar(startPos, ' ');
		std::cout << "|" << equip[i].name << "|" << std::endl;
		Utils::AddChar(startPos, ' ');
		Utils::AddChar(length, '-');
	}
}
